TITLE Register List    (Reglist.asm)

; Local variables, register lists.
; Evaluates code generated by the assembler.
; Last update: 06/01/2006

INCLUDE Irvine32.inc

.code
main PROC

	exit
main ENDP

BubbleSort PROC
	LOCAL temp:DWORD, SwapFlag:BYTE
	;
	ret
BubbleSort ENDP

MySub PROC USES eax ebx
	;
	;
	ret
MySub ENDP

Swap PROC USES ecx edx,
	pValX:PTR DWORD,
	pValY:PTR DWORD
LOCAL temp:DWORD
	;
	ret
Swap ENDP

END main