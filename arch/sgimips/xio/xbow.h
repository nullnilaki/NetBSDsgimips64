/*  $OpenBSD: xbow.h,v 1.12 2011/04/17 17:44:24 miod Exp $  */

/*
 * Copyright (c) 2008 Miodrag Vallat.
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
 * Devices connected to the XBow are called ``widgets'' and are
 * identified by a common widget memory area at the beginning of their
 * memory space.
 *
 * Each widget has its own memory space.  The lowest 16MB are always
 * accessible as a so-called ``short window''.  Other `views' of the
 * widget are possible, depending on the system (the whole widget
 * address space is always visible on Octane, while Origin family
 * systems can only map a few ``large windows'', which are a scarce
 * resource).
 *
 * Apart from the crossbow itself being widget #0, the widgets are divided
 * in two groups: widgets #8 to #b are the ``upper'' widgets, while widgets
 * #c to #f are the ``lower'' widgets.
 *
 * Widgets are uniquely identified with their widget number on the XBow
 * bus. However, the way they are mapped and accessed will depend on the
 * processor (well, the processor board node) requesting access. Hence the
 * two parameters needed to map a widget.
 */

/*
 * Valid widget values
 */

#define WIDGET_MIN          8
#define WIDGET_MAX          15

void    xbow_build_bus_space(struct mips_bus_space *, bus_addr_t);