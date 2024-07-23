	.file	"program.c"
	.option nopic
	.attribute arch, "rv32i2p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.align	2
	.globl	sieve
	.type	sieve, @function
sieve:
	lui	a5,%hi(.LANCHOR0)
	addi	a5,a5,%lo(.LANCHOR0)
	addi	a4,a5,20
.L2:
	sh	zero,0(a5)
	addi	a5,a5,2
	bne	a5,a4,.L2
	lui	a5,%hi(.LANCHOR0+2)
	li	a4,-1
	sh	a4,%lo(.LANCHOR0+2)(a5)
	li	a5,1
	li	a2,9
	lui	a7,%hi(.LANCHOR0)
	addi	a7,a7,%lo(.LANCHOR0)
	li	a6,-1
	li	a0,10
	li	t1,4
	j	.L7
.L8:
	mv	a5,a3
.L3:
	slli	a3,a5,1
	bgt	a3,a2,.L5
	mv	a1,a3
	slli	a4,a3,1
	add	a4,a7,a4
.L6:
	sh	a6,0(a4)
	add	a3,a3,a5
	add	a4,a4,a1
	ble	a3,a2,.L6
.L5:
	bgt	a5,t1,.L13
.L7:
	addi	a3,a5,1
	bgt	a3,a2,.L8
	slli	a5,a3,1
	add	a4,a7,a5
	mv	a5,a3
.L4:
	lhu	a3,0(a4)
	beq	a3,zero,.L3
	addi	a5,a5,1
	addi	a4,a4,2
	bne	a5,a0,.L4
	j	.L5
.L13:
	ebreak
	.size	sieve, .-sieve
	.align	2
	.globl	main
	.type	main, @function
main:
	addi	sp,sp,-16
	sw	ra,12(sp)
	call	sieve
	li	a0,0
	lw	ra,12(sp)
	addi	sp,sp,16
	jr	ra
	.size	main, .-main
	.globl	mark
	.bss
	.align	2
	.set	.LANCHOR0,. + 0
	.type	mark, @object
	.size	mark, 20
mark:
	.zero	20
	.ident	"GCC: () 12.2.0"
