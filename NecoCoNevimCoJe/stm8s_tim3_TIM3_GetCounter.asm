;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler 
; Version 4.4.0 #14620 (Linux)
;--------------------------------------------------------
	.module stm8s_tim3_TIM3_GetCounter
	.optsdcc -mstm8
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _TIM3_GetCounter
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area DATA
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area INITIALIZED
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area DABS (ABS)

; default segment ordering for linker
	.area HOME
	.area GSINIT
	.area GSFINAL
	.area CONST
	.area INITIALIZER
	.area CODE

;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME
	.area GSINIT
	.area GSFINAL
	.area GSINIT
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME
	.area HOME
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CODE
;	../SPLSPL/src/stm8s_tim3_TIM3_GetCounter.c: 36: uint16_t TIM3_GetCounter(void)
; genLabel
;	-----------------------------------------
;	 function TIM3_GetCounter
;	-----------------------------------------
;	Register assignment might be sub-optimal.
;	Stack space usage: 2 bytes.
_TIM3_GetCounter:
	pushw	x
;	../SPLSPL/src/stm8s_tim3_TIM3_GetCounter.c: 40: tmpcntr = ((uint16_t)TIM3->CNTRH << 8);
; genPointerGet
	ld	a, 0x5328
; genCast
; genAssign
	clrw	x
; genLeftShiftLiteral
	ld	xh, a
	clr	(0x02, sp)
;	../SPLSPL/src/stm8s_tim3_TIM3_GetCounter.c: 42: return (uint16_t)( tmpcntr| (uint16_t)(TIM3->CNTRL));
; genPointerGet
	ld	a, 0x5329
; genCast
; genAssign
	clrw	y
; genOr
; genReturn
	ld	xl, a
; genLabel
00101$:
;	../SPLSPL/src/stm8s_tim3_TIM3_GetCounter.c: 43: }
; genEndFunction
	addw	sp, #2
	ret
	.area CODE
	.area CONST
	.area INITIALIZER
	.area CABS (ABS)
