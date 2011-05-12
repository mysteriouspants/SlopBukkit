title short program to perform some numerical operations
; (C) 2010 Chris Miller, All Right Reserved.
; Academic endorsement.
; Created: 20100223
include irvine32.inc
.data
	val1 SDWORD 8
	val2 SDWORD -15
	val3 SDWORD 20
.code
main proc
	mov eax, val2 	; eax -0x000F
	neg eax 				; eax 0x000F
	add eax, 7 			; eax 0x0017
	mov edx, val3 	; edx 0x0015
	sub eax, edx 		; eax 0x0002
	mov edx, val1		; edx 0x0008
	add eax, edx		; eax 0x000A
	mov ax, 0FFFFh
	inc ax
	call DumpRegs
	mov ax, 0FFFFh
	add ax, 1
	call DumpRegs
	exit
main endp
end main
