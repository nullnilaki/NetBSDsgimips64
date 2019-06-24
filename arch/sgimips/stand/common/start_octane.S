#include <mips/asm.h>
#include <mips/cpuregs.h>

	.text
	.align  3
	.set	noreorder
	.globl	start
start:
#ifdef __GP_SUPPORT__
	dla	gp, _C_LABEL (_gp)
#endif
	daddi	sp, - (CALLFRAME_SIZ * 2)
	sd	ra, CALLFRAME_RA * 2(sp)	# Save RA
	sd	a0, 0(sp)			# save argc
	sd	a1, 8(sp)			# save argv
	sd	a2, 16(sp)			# save envp
	dla v0, 0xffffffff80001000
	ld  v0, 2*0x20(v0)
	sd	v0, _C_LABEL(ARCBIOS)		# save ARCBIOS
	dla	a0, _C_LABEL (edata)		# clear BSS
	move	a1, zero
	dla	a2, _C_LABEL (end)
	jal	_C_LABEL(memset)		# memset(edata, 0, end - edata)
		dsubu	a2, a2, a0
	ld	a0, 0(sp)			# restore argc
	ld	a1, 8(sp)			# restore argv
	jal	_C_LABEL(main)			# main(argc, argv)
	ld	a2, 16(sp)			# restore envp
	ld	ra, CALLFRAME_RA * 2(sp)	# restore RA
	j	ra				# return to PROM
	daddi	sp, CALLFRAME_SIZ * 2		# BDslot: adjust stack


LEAF(romrestart)
XLEAF(_rtt)
	dla $2, 0xffffffff80001000
	ld  $3, 2*0x20($2)
	ld  $2, 2*0x18($3)
	jr  $2
	nop
END(romrestart)

	.data
	.global	ARCBIOS
ARCBIOS: PTR_WORD	0