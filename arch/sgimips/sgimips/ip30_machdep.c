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

#if 0
#define XKPHYS_BASE     0x8000000000000000UL
#define PHYS_TO_XKPHYS(x,c) ((paddr_t)(x) | XKPHYS_BASE | ((c) << 59))

paddr_t
ip30_widget_long(int16_t nasid, u_int widget)
{
    return PHYS_TO_XKPHYS((uint64_t)(widget) << 36, CCA_NC);
}
#endif