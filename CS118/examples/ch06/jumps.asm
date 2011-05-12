TITLE Conditional Jumps             (jumps.asm)

; Demonstrates conditional jumps
; Last update: 06/01/2006

.386
.model flat,stdcall
.stack 100h

code segment 'CODE'
main PROC


	mov	ax,bx
	nop			; align next instruction
	mov	edx,ecx


	jz FarLabel
	nop	
	nop
	nop

	mov	ax,4C00h
	int	21h
main ENDP
code ends

other segment 'CODE'

FarLabel:
	


other ends




END main