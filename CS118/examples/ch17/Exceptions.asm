TITLE Unmasking an Exception  	(Exceptions.asm)

; Last update: 06/01/2006

INCLUDE Irvine32.inc

.code
main PROC
	finit		; initialize FPU

.data
ctrlWord WORD ?
val1 DWORD 1
val2 REAL8 0.0

.code

	fstcw	ctrlWord				; get the control word
	and	ctrlWord,1111111111111011b	; unmask Divide by 0
	fldcw	ctrlWord				; load it back into FPU

	fild	val1
	fdiv	val2						; divide by zero
	fst	val2
	
	exit
main ENDP
END main