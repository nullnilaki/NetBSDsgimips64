#!/bin/sh
#
# Public domain
#

HDRS="asm.h"
HDRS="$HDRS bswap.h"
HDRS="$HDRS byte_swap.h"
HDRS="$HDRS disklabel.h"
HDRS="$HDRS elf_machdep.h"
HDRS="$HDRS endian.h"
HDRS="$HDRS endian_machdep.h"
HDRS="$HDRS int_const.h"
HDRS="$HDRS int_fmtio.h"
HDRS="$HDRS int_limits.h"
HDRS="$HDRS int_mwgwtypes.h"
HDRS="$HDRS int_types.h"
HDRS="$HDRS limits.h"
HDRS="$HDRS netbsd32_machdep.h"
HDRS="$HDRS param.h"
HDRS="$HDRS ptrace.h"
HDRS="$HDRS wchar_limits.h"
HDRS="$HDRS cdefs.h"
HDRS="$HDRS mcontext.h"
HDRS="$HDRS frame_regs.h"
HDRS="$HDRS cpufunc.h"

for hdr in ${HDRS}; do
	G="_USERMODE_$(echo ${hdr} | sed 's/\./_/g' | tr [a-z] [A-Z])"

	cat > ${hdr} << EOF
/* \$NetBSD\$ */

/*
 * Automatically generated by $0 on $(date)
 * Do not modify directly!
 */
#ifndef $G
#define $G

#if defined(__i386__)
#include "../../i386/include/${hdr}"
#elif defined(__x86_64__)
#include "../../amd64/include/${hdr}"
#elif defined(__arm__)
#include "../../arm/include/${hdr}"
#else
#error port me
#endif
EOF

	# header specific quirks
	if [ "$hdr" = "disklabel.h" ]; then
		echo "#include <machine/types.h>" >> ${hdr}
		echo "#ifndef __HAVE_OLD_DISKLABEL" >> ${hdr}
		echo "#undef DISKUNIT" >> ${hdr}
		echo "#undef DISKPART" >> ${hdr}
		echo "#undef DISKMINOR" >> ${hdr}
		echo "#endif" >> ${hdr}
	elif [ "$hdr" = "ptrace.h" ]; then
		echo "#undef __HAVE_PTRACE_MACHDEP" >> ${hdr}
		echo "#undef __HAVE_PROCFS_MACHDEP" >> ${hdr}
	elif [ "$hdr" = "param.h" ]; then
		cat >> ${hdr} << EOF
#ifdef __arm__
#define MACHINE "evbarm"
#define PGSHIFT 12
#define NBPG (1 << PGSHIFT)
#define PGOFSET (NBPG - 1)
#define NKMEMPAGES_MIN_DEFAULT  ((8 * 1024 * 1024) >> PAGE_SHIFT)
#endif
EOF
		echo "#undef UPAGES" >> ${hdr}
		echo "#define UPAGES 12" >> ${hdr}
		echo "#undef USPACE" >> ${hdr}
		echo "#define USPACE (PAGE_SIZE*UPAGES)" >> ${hdr}
		echo "" >> ${hdr}
		echo "#undef NKMEMPAGES_MAX_UNLIMITED" >> ${hdr}
		echo "#include \"opt_kmempages.h\"" >> ${hdr}
		echo "" >> ${hdr}
	elif [ "$hdr" = "elf_machdep.h" ]; then
		echo "#ifdef ELF_MD_PROBE_FUNC" >> ${hdr}
		echo "#undef ELF_MD_PROBE_FUNC" >> ${hdr}
		echo "#endif" >> ${hdr}
	fi

	echo >>${hdr}
	echo "#endif" >> ${hdr}
done
