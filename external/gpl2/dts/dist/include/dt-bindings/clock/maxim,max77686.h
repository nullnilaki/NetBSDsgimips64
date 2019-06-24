/*	$NetBSD: maxim,max77686.h,v 1.1.1.1 2017/06/15 20:14:23 jmcneill Exp $	*/

/*
 * Copyright (C) 2014 Google, Inc
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Device Tree binding constants clocks for the Maxim 77686 PMIC.
 */

#ifndef _DT_BINDINGS_CLOCK_MAXIM_MAX77686_CLOCK_H
#define _DT_BINDINGS_CLOCK_MAXIM_MAX77686_CLOCK_H

/* Fixed rate clocks. */

#define MAX77686_CLK_AP		0
#define MAX77686_CLK_CP		1
#define MAX77686_CLK_PMIC	2

/* Total number of clocks. */
#define MAX77686_CLKS_NUM		(MAX77686_CLK_PMIC + 1)

#endif /* _DT_BINDINGS_CLOCK_MAXIM_MAX77686_CLOCK_H */
