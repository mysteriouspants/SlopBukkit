TITLE Test ModR/M Byte			(ModRM.asm)

; Last update: 06/01/2006

.386
.model flat,stdcall
.stack 100h

.data
byte1  BYTE ?
word1  WORD ?
dword1 DWORD ?

.code
main PROC

	mov	bl,byte1
	mov	bx,word1
	mov	ebx,dword1


	mov ax,4c00h
	int 21h
main ENDP
END main