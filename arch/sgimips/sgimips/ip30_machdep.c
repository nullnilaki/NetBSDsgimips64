/*  $OpenBSD: ip30_machdep.c,v 1.69 2018/01/29 14:51:57 visa Exp $  */

/*
 * Copyright (c) 2008, 2009 Miodrag Vallat.
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
 * Octane (IP30) specific code.
 */


#include <sys/param.h>
#include <sys/device.h>
#include <sys/systm.h>
#include <sys/cpu.h>

#include <uvm/uvm_extern.h>

#include <machine/locore.h>
#include <machine/psl.h>
#include <machine/autoconf.h>
#include <machine/machtype.h>
#include <machine/sysconf.h>

#include <sgimips/sgimips/ip30.h>
#include <sgimips/xio/widget.h>
#include <sgimips/xio/xbow.h>
#include <sgimips/xio/xbowdevs.h>
#include <sgimips/xio/xbridgereg.h>    /* BRIDGE_PCI0_MEM_SPACE_BASE */



paddr_t ip30_widget_short(int16_t, u_int);
paddr_t ip30_widget_long(int16_t, u_int);
paddr_t ip30_widget_map(int16_t, u_int, bus_addr_t *, bus_size_t *);
int ip30_widget_id(int16_t, u_int, uint32_t *);

void
ip30_setup(void)
{
    xbow_widget_base = ip30_widget_short;
    xbow_widget_map = ip30_widget_map;
    xbow_widget_id = ip30_widget_id;
}

/*
 * Widget mapping. IP30 only has one processor board node, so the nasid
 * parameter is ignored.
 */

paddr_t
ip30_widget_short(int16_t nasid, u_int widget)
{
    return PHYS_TO_XKPHYS(((uint64_t)widget << 24) | (1ULL << 28), CCA_NC);
}

paddr_t
ip30_widget_long(int16_t nasid, u_int widget)
{
    return PHYS_TO_XKPHYS((uint64_t)(widget) << 36, CCA_NC);
}

paddr_t
ip30_widget_map(int16_t nasid, u_int widget, bus_addr_t *offs, bus_size_t *len)
{
    paddr_t base;

    /*
     * On Octane, the whole widget space is always accessible.
     */

    base = ip30_widget_long(nasid, widget);
    *len = (1ULL << 36) - *offs;

    return base + *offs;
}

/*
 * Widget enumeration
 */

int
ip30_widget_id(int16_t nasid, u_int widget, uint32_t *wid)
{
    paddr_t linkpa, wpa;

    if (widget != 0) {
        if (widget < WIDGET_MIN || widget > WIDGET_MAX)
            return EINVAL;

        linkpa = ip30_widget_short(nasid, 0) + XBOW_WIDGET_LINK(widget);
        if (!ISSET(*(uint32_t *)(linkpa + (WIDGET_LINK_STATUS | 4)),
            WIDGET_STATUS_ALIVE))
            return ENXIO;   /* not connected */
    }

    wpa = ip30_widget_short(nasid, widget);
    if (wid != NULL)
        *wid = *(uint32_t *)(wpa + (WIDGET_ID | 4));

    return 0;
}
