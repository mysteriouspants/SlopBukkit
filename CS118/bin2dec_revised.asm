title Converts binary to decimal
;#include<stdio.h>
includelib libcmt		; multi-threaded static linked C library
.486
.model flat
.stack 4096
.data
; int tempt = 0;
temp SDWORD 0
; unsigned int bits[32]
bits DWORD 32 dup(?)
; unsigned int total = 0;
total DWORD 0
; int i=0,j;
i SDWORD 0
j SDWORD ?
msg BYTE "Input a binary number to be converted to decimal:",0
extern _printf:proc
extern _getchar:proc
.code
_main proc
	push ebp
	mov ebp,esp
;int main()
;{
;	
	push OFFSET msg
	call _printf
	add esp,4
;	printf( "Input a binary number to be converted to decimal:" );	/* Ask for input */
;	for ( ;; ++i )	/* For loop */
	L1:
;	{
;		temp = getchar();	/* Get characters, one at a time */
;		/*printf( "Temp is %d \n", temp );*/
;		if ( temp < 48 || temp > 49 )	/* Assume any non-binary character is EOI */
;			break;	/* They typed something goofy?  BOMB THEM! */
;		bits[i] = temp - '0';	/* Set the current bit value */
;		for ( j = 0; j < i; ++j )	/* For loop to double past bits */
;			bits[j] = bits[j] * 2;	/* Double the bit */
;	}
		mov eax,i
		inc i
		mov i,eax
		jmp L1
;	for ( j = 0; j < i; ++j )	/* For loop - go through bits array and sum */
	mov eax,0
	L2:
		mov eax,j
		mov ebx,i
		cmp eax,ebx
		mov j,eax
		
;		total += bits[j];	/* Actual summation */
		jnl L3
;	printf( "The resulting decimal number is %u\n", total );	/* Output result */
;}
		mov eax,j
		inc eax
		mov j,eax
		jmp L2
	L3:
	pop ebp
	ret 0h
_main endp
end
