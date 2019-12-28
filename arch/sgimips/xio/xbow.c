/*  $OpenBSD: xbow.c,v 1.35 2014/09/30 06:51:58 jmatthew Exp $  */

/*
 * Copyright (c) 2008, 2009, 2011 Miodrag Vallat.
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */
/*
 * Copyright (c) 2004 Opsycon AB  (www.opsycon.se)
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 */

/*
 *  XBOW is the mux between two nodes and XIO.
 *
 *  A Crossbow (XBOW) connects two nodeboards via their respective
 *  HUB to up to six different I/O controllers in XIO slots. In a
 *  multiprocessor system all processors have access to the XIO
 *  slots but may need to pass traffic via the routers.
 *
 *  To each XIO port on the XBOW a XIO interface is attached. Such
 *  interfaces can be for example PCI bridges which then add another
 *  level to the hierarchy.
 */

#include <sys/param.h>
#include <sys/systm.h>
#include <sys/device.h>
#include <sys/callout.h>
#include <sys/mbuf.h>
#include <sys/malloc.h>
#include <sys/kernel.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <sys/errno.h>
#include <sys/syslog.h>

#include <uvm/uvm_extern.h>

#include <sys/bus.h>
#include <machine/cpu.h>
#include <machine/locore.h>
#include <machine/autoconf.h>
#include <machine/machtype.h>

#include <sgimips/xio/xbow.h>

struct xbow_softc {
	device_t sc_dev;

	bus_space_tag_t iot;
	bus_space_handle_t ioh;
};

CFATTACH_DECL_NEW(xbow, sizeof(struct xbow_softc),
    NULL, NULL, NULL, NULL);

static void xbow_bus_mem_init(bus_space_tag_t, void *);
static struct mips_bus_space    xbow_mbst;
bus_space_tag_t xbow_memt = NULL;

/*
 * Function pointers to hide widget discovery and mapping differences accross
 * systems.
 */
paddr_t (*xbow_widget_base)(int16_t, u_int);
paddr_t (*xbow_widget_map)(int16_t, u_int, bus_addr_t *, bus_size_t *);

int (*xbow_widget_id)(int16_t, u_int, uint32_t *);

/*
 * Bus access primitives.
 */

void
xbow_build_bus_space(struct mips_bus_space *bs, bus_addr_t bus_base)
{
    xbow_bus_mem_init(&xbow_mbst, NULL);
    xbow_memt = &xbow_mbst;
}

#define CHIP            xbow
#define CHIP_MEM        /* defined */
#define	CHIP_W1_BUS_START(v)	0x900000f040500000ULL
#define	CHIP_W1_BUS_END(v)	    0x900000f040500000ULL + 0x0000000040000000ULL
#define	CHIP_W1_SYS_START(v)	0x900000f040500000ULL
#define	CHIP_W1_SYS_END(v)	    0x900000f040500000ULL + 0x0000000040000000ULL

#include <mips/mips/bus_space_alignstride_chipdep.c>