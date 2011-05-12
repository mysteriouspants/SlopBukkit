TITLE Test 16-bit Code Generation      (Test16a.asm)

; 16-bit application, using 16-bit processor
; Last update: 06/01/2006

.model small
.286
.stack 100h

.code
main PROC
	mov ax,dx
	mov al,dl
	mov cx,dx
	mov cl,dl

	mov ax,4c00h
	int 21h
main ENDP
END main