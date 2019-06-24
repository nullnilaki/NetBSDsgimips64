/* $NetBSD: tegra_usbreg.h,v 1.2 2017/01/22 17:46:20 jakllsch Exp $ */

/*-
 * Copyright (c) 2015 Jared D. McNeill <jmcneill@invisible.ca>
 * All rights reserved.
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
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef _ARM_TEGRA_USBREG_H
#define _ARM_TEGRA_USBREG_H

#define TEGRA_EHCI_TXFILLTUNING_REG		0x154
#define TEGRA_EHCI_TXFILLTUNING_TXFIFOTHRES	__BITS(21,16)

#define TEGRA_EHCI_ICUSB_CTRL_REG		0x15c
#define TEGRA_EHCI_ICUSB_CTRL_ENB1		__BIT(3)
#define TEGRA_EHCI_ICUSB_CTRL_VDD1		__BITS(2,0)

#define TEGRA_EHCI_HOSTPC1_DEVLC_REG		0x1b4
#define TEGRA_EHCI_HOSTPC1_DEVLC_PTS		__BITS(31,29)
#define TEGRA_EHCI_HOSTPC1_DEVLC_PTS_UTMI	0
#define TEGRA_EHCI_HOSTPC1_DEVLC_PTS_ULPI	2
#define TEGRA_EHCI_HOSTPC1_DEVLC_PTS_ICUSB_SER	3
#define TEGRA_EHCI_HOSTPC1_DEVLC_STS		__BIT(28)
#define TEGRA_EHCI_HOSTPC1_DEVLC_PTW		__BIT(27)
#define TEGRA_EHCI_HOSTPC1_DEVLC_PSPD		__BITS(26,25)
#define TEGRA_EHCI_HOSTPC1_DEVLC_PSPD_FS	0
#define TEGRA_EHCI_HOSTPC1_DEVLC_PSPD_LS	1
#define TEGRA_EHCI_HOSTPC1_DEVLC_PSPD_HS	2
#define TEGRA_EHCI_HOSTPC1_DEVLC_ALPD		__BIT(24)
#define TEGRA_EHCI_HOSTPC1_DEVLC_PFSC		__BIT(23)
#define TEGRA_EHCI_HOSTPC1_DEVLC_PHCD		__BIT(22)
#define TEGRA_EHCI_HOSTPC1_DEVLC_H_LPMX		__BITS(21,20)
#define TEGRA_EHCI_HOSTPC1_DEVLC_H_EPLPM	__BITS(19,16)
#define TEGRA_EHCI_HOSTPC1_DEVLC_H_LPMFRM	__BITS(15,12)
#define TEGRA_EHCI_HOSTPC1_DEVLC_D_ASUS		__BIT(17)
#define TEGRA_EHCI_HOSTPC1_DEVLC_D_STL		__BIT(16)
#define TEGRA_EHCI_HOSTPC1_DEVLC_BA		__BITS(11,1)

#define TEGRA_EHCI_USBMODE_REG			0x1f8
#define TEGRA_EHCI_USBMODE_CM			__BITS(1,0)
#define TEGRA_EHCI_USBMODE_CM_IDLE		0
#define TEGRA_EHCI_USBMODE_CM_DEVICE		2
#define TEGRA_EHCI_USBMODE_CM_HOST		3

#define TEGRA_EHCI_SUSP_CTRL_REG		0x400
#define TEGRA_EHCI_SUSP_CTRL_UHSIC_RESET	__BIT(14)
#define TEGRA_EHCI_SUSP_CTRL_ULPI_PHY_ENB	__BIT(13)
#define TEGRA_EHCI_SUSP_CTRL_UTMIP_PHY_ENB	__BIT(12)
#define TEGRA_EHCI_SUSP_CTRL_UTMIP_RESET	__BIT(11)
#define TEGRA_EHCI_SUSP_CTRL_PHY_CLK_VALID	__BIT(7)

#define TEGRA_EHCI_PHY_VBUS_SENSORS_REG		0x404
#define TEGRA_EHCI_PHY_VBUS_SENSORS_A_VBUS_VLD_STS __BIT(26)
#define TEGRA_EHCI_PHY_VBUS_SENSORS_B_VLD_SW_VALUE __BIT(12)
#define TEGRA_EHCI_PHY_VBUS_SENSORS_B_VLD_SW_EN	__BIT(11)

#define TEGRA_EHCI_PHY_VBUS_WAKEUP_ID_REG	0x408
#define TEGRA_EHCI_PHY_VBUS_WAKEUP_ID_ID_PU		__BIT(6)
#define TEGRA_EHCI_PHY_VBUS_WAKEUP_ID_ID_DEB_SEL_B	__BIT(5)
#define TEGRA_EHCI_PHY_VBUS_WAKEUP_ID_ID_SW_VALUE	__BIT(4)
#define TEGRA_EHCI_PHY_VBUS_WAKEUP_ID_ID_SW_EN		__BIT(3)
#define TEGRA_EHCI_PHY_VBUS_WAKEUP_ID_ID_STS		__BIT(2)
#define TEGRA_EHCI_PHY_VBUS_WAKEUP_ID_ID_CHG_DET	__BIT(1)
#define TEGRA_EHCI_PHY_VBUS_WAKEUP_ID_ID_INT_EN		__BIT(0)

#define TEGRA_EHCI_UTMIP_XCVR_CFG0_REG		0x808
#define TEGRA_EHCI_UTMIP_XCVR_CFG0_HSSLEW_MSB	__BITS(31,25)
#define TEGRA_EHCI_UTMIP_XCVR_CFG0_SETUP_MSB	__BITS(24,22)
#define TEGRA_EHCI_UTMIP_XCVR_CFG0_LSBIAS_SEL	__BIT(21)
#define TEGRA_EHCI_UTMIP_XCVR_CFG0_SETUP	__BITS(3,0)
#define TEGRA_EHCI_UTMIP_XCVR_CFG0_PDZI_POWERDOWN __BIT(18)
#define TEGRA_EHCI_UTMIP_XCVR_CFG0_PD2_POWERDOWN __BIT(16)
#define TEGRA_EHCI_UTMIP_XCVR_CFG0_PD_POWERDOWN	__BIT(14)

#define TEGRA_EHCI_UTMIP_BIAS_CFG0_REG		0x80c
#define TEGRA_EHCI_UTMIP_BIAS_CFG0_HSDISCON_LEVEL_MSB __BIT(24)
#define TEGRA_EHCI_UTMIP_BIAS_CFG0_BIASPD	__BIT(10)
#define TEGRA_EHCI_UTMIP_BIAS_CFG0_HSDISCON_LEVEL __BITS(3,2)

#define TEGRA_EHCI_UTMIP_TX_CFG0_REG		0x820
#define TEGRA_EHCI_UTMIP_TX_CFG0_FS_PREAMBLE_J	__BIT(19)

#define TEGRA_EHCI_UTMIP_MISC_CFG0_REG		0x824
#define TEGRA_EHCI_UTMIP_MISC_CFG0_SUSPEND_EXIT_ON_EDGE __BIT(22)

#define TEGRA_EHCI_UTMIP_MISC_CFG1_REG		0x828
#define TEGRA_EHCI_UTMIP_MISC_CFG1_PHY_XTAL_CLOCKEN __BIT(30)

#define TEGRA_EHCI_UTMIP_DEBOUNCE_CFG0_REG	0x82c
#define TEGRA_EHCI_UTMIP_DEBOUNCE_CFG0_B	__BITS(31,16)
#define TEGRA_EHCI_UTMIP_DEBOUNCE_CFG0_A	__BITS(15,0)

#define TEGRA_EHCI_UTMIP_BAT_CHRG_CFG0_REG	0x830
#define TEGRA_EHCI_UTMIP_BAT_CHRG_CFG0_PD_CHRG	__BIT(0)

#define TEGRA_EHCI_UTMIP_SPARE_CFG0_REG		0x834

#define TEGRA_EHCI_UTMIP_XCVR_CFG1_REG		0x838
#define TEGRA_EHCI_UTMIP_XCVR_CFG1_TERM_RANGE_ADJ __BITS(21,18)
#define TEGRA_EHCI_UTMIP_XCVR_CFG1_PDDR_POWERDOWN __BIT(4)
#define TEGRA_EHCI_UTMIP_XCVR_CFG1_PDCHRP_POWERDOWN __BIT(2)
#define TEGRA_EHCI_UTMIP_XCVR_CFG1_PDDISC_POWERDOWN __BIT(0)

#define TEGRA_EHCI_UTMIP_BIAS_CFG1_REG		0x83c
#define TEGRA_EHCI_UTMIP_BIAS_CFG1_PDTRK_COUNT	__BITS(7,3)
#define TEGRA_EHCI_UTMIP_BIAS_CFG1_PDTRK_POWERDOWN __BIT(0)

#define TEGRA_EHCI_UTMIP_HSRX_CFG0_REG		0xc08
#define TEGRA_EHCI_UTMIP_HSRX_CFG0_IDLE_WAIT	__BITS(19,15)
#define TEGRA_EHCI_UTMIP_HSRX_CFG0_ELASTIC_LIMIT __BITS(14,10)

#define TEGRA_EHCI_UTMIP_HSRX_CFG1_REG		0xc0c
#define TEGRA_EHCI_UTMIP_HSRX_CFG1_SYNC_START_DLY __BITS(5,1)

#endif /* _ARM_TEGRA_USBREG_H */
