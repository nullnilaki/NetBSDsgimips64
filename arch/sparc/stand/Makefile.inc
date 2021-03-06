#	$NetBSD: Makefile.inc,v 1.14 2016/10/01 13:57:44 christos Exp $

NOSSP=		# defined
NOPIE=		# defined
NOMAN=		# defined

BINDIR=		/usr/mdec
NOPIE=		yes

CPPFLAGS+=	-DSTANDALONE -I.
CFLAGS+=	-ffreestanding ${${ACTIVE_CC} == "gcc":? -msoft-float :}

.if ${MACHINE} == "sparc64"
CPPFLAGS+=	-DSUN4U
.endif
