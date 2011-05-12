TITLE Demonstrate local variables   (LocalVars.asm)

; Last update: 06/01/2006

INCLUDE Irvine32.inc

.data

.code
main PROC

	call	MySub
	
	exit

main ENDP


X_local EQU DWORD PTR [ebp-4]
Y_local EQU DWORD PTR [ebp-8]

MySub PROC
	push	ebp
	mov	ebp,esp
	sub	esp,8		; create variables
	mov	X_local,20	; X
	mov	Y_local,10	; Y
	mov	esp,ebp		; remove locals from stack
	pop	ebp
	ret
MySub ENDP


END main

; ALTERNATE VERSION:

MySub PROC
	push	ebp
	mov	ebp,esp
	sub	esp,8				; create variables
	mov	DWORD PTR [ebp-4],20	; X
	mov	DWORD PTR [ebp-8],10	; Y
	mov	esp,ebp				; remove locals from stack
	pop	ebp
	ret
MySub ENDP

