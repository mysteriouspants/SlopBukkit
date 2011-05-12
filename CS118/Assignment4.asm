title short program to perform some numerical operations
; (C) 2010 Chris Miller, All Right Reserved.
; Academic endorsement.
; Created: 20100310
include irvine32.inc
.data
	; int array[] = { 10,60,20,33,72,89,45,65,72,18};
	array SDWORD 10,60,20,33,72,89,45,65,72,18
	;	int ArraySize = sizeof array / sizeof sample;
	ArraySize SDWORD ($ - array)
	;	int sample = 50;
	sample SDWORD 50
	; int index = 0;
	index SDWORD 0
	; int sum = 0;
	sum SDWORD 0
.code
main proc
	; while( index < ArraySize )
	WHILE1:
		mov eax, index
		mov ebx, ArraySize
		cmp eax, ebx
		jz  WEND1
		; if( array[ index] <= sample )
		mov ebx, index
		mov eax, array[ebx]
		mov ebx, sample
		cmp eax, ebx
		jae IFF
		; sum += array[ index];     
		mov eax, index
		mov ebx, array[eax]
		mov eax, sum
		add eax, ebx
		mov sum, eax
		IFF:
		; index++;
		mov eax, index
		inc eax
		mov index, eax
		jmp WHILE1
	WEND1:
	mov eax, sum
	call WriteInt
	exit
main endp
end main