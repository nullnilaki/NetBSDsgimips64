/*  $OpenBSD: com_ioc.c,v 1.9 2012/10/03 22:46:09 miod Exp $ */

/*
 * Copyright (c) 2001-2004 Opsycon AB  (www.opsycon.se / www.opsycon.com)
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

#include <sys/param.h>
#include <sys/systm.h>
#include <sys/device.h>
#include <sys/tty.h>

#include <machine/autoconf.h>
#include <machine/bus.h>
#include <machine/intr.h>

#include <machine/autoconf.h>

#include <dev/ic/comreg.h>
#include <dev/ic/comvar.h>

struct com_ioc3_softc {
    struct com_softc sc_com;
    void *sc_ih;
};

static int  com_ioc3_probe(device_t, cfdata_t , void *);
static void com_ioc3_attach(device_t, device_t, void *);

CFATTACH_DECL_NEW(com_ioc3, sizeof(struct com_ioc3_softc),
    com_ioc3_probe, com_ioc3_attach, NULL, NULL);

int
com_ioc3_probe(device_t parent, cfdata_t match, void *aux)
{
    if (arcbios_GetEnvironmentVariable("ConsoleOut") == NULL)
        panic("com_ioc3_probe without valid ARCS ConsoleOut setting!");

    return 1;
}

void
com_ioc3_attach(struct device *parent, device_t self, void *aux)
{
#if 0
    struct com_ioc3_softc *ioc3sc = device_private(self);
    struct com_softc *sc = &ioc3sc->sc_com;
    struct ioc3_attach_args *iaa = aux;
    bus_space_handle_t ioh;
    bus_space_handle_t  ioh;

    sc->sc_dev = self;
    if (!com_is_console(maa->ma_iot, maa->ma_addr, &ioh) &&
        bus_space_map(maa->ma_iot, maa->ma_addr, COM_NPORTS, 0, &ioh)) {
        aprint_error(": can't map i/o space\n");
        return;
    }
    com_init_regs(&sc->sc_regs, maa->ma_iot, ioh, maa->ma_addr);

    sc->sc_frequency = 22000000 / 3;

    com_attach_subr(sc);

    ioc_intr_establish(parent, iaa->iaa_dev, IPL_TTY, comintr,
        (void *)sc, sc->sc_dev.dv_xname);
#endif
    panic("com_ioc3_attach");
    return;
}

void
com_ioc3_cnprobe(struct consdev *cn)
{
    cp->cn_pri = CN_REMOTE;
}

extern struct mips_bus_space ioc3_bs;

void
com_ioc3_cninit(struct consdev *cn)
{

    comcnattach(&ioc3_bs, COM_BASE, 115200, COM_MAINBUS_FREQ, COM_TYPE_NORMAL,
        CONMODE);
}
