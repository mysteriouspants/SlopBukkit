TITLE Test 386 Code Generation      (Test16b.asm)

; operand-size prefix demonstration
; Last update: 06/01/2006

.386
.model flat,stdcall
.stack 100h

.code
main PROC

	mov	al,[ecx]
	mov di,[edx]

	mov	ax,dx	; operand prefix 66
	mov	al,dl

; demonstrate opcodes
	mov	al,bl
	mov	ax,bx
	mov	eax,ebx

	mov ax,4c00h
	int 21h
main ENDP
END main