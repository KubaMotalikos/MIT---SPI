;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler 
; Version 4.4.0 #14620 (Linux)
;--------------------------------------------------------
	.module stm8s_can_CAN_GetReceivedFMI
	.optsdcc -mstm8
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _CAN_GetReceivedFMI
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
;	../SPLSPL/src/stm8s_can_CAN_GetReceivedFMI.c: 40: uint8_t CAN_GetReceivedFMI(void)
; genLabel
;	-----------------------------------------
;	 function CAN_GetReceivedFMI
;	-----------------------------------------
;	Register assignment is optimal.
;	Stack space usage: 0 bytes.
_CAN_GetReceivedFMI:
;	../SPLSPL/src/stm8s_can_CAN_GetReceivedFMI.c: 42: return (_FMI);
; genReturn
	ld	a, __FMI+0
; genLabel
00101$:
;	../SPLSPL/src/stm8s_can_CAN_GetReceivedFMI.c: 43: }
; genEndFunction
	ret
	.area CODE
	.area CONST
	.area INITIALIZER
	.area CABS (ABS)
