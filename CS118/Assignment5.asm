title short program to take decimal numbers and display them in hex and binary
; (C) 2010 Chris Miller, All Right Reserved.
; Academic endorsement.
; Created: 20100317
include irvine32.inc
.data
	
	prompt BYTE "Enter an integer: ",0
	
	print_theNumber SDWORD ?
	print_label0 BYTE "In Hex is: ",0
	print_label1 BYTE "In Binary is: ",0
	print_label2 BYTE "Number of bits set is: ",0
	print_bit SDWORD ?
	print_bitsSet SDWORD ?
	
	continuelabel BYTE "Press the any key to exit",0
	
.code
; takes a 32-bit signed integer from eax and prints out
; information about it
print PROC
	mov edx,OFFSET print_label0
	call WriteString
	mov eax,print_theNumber
	call WriteHex
	call Crlf
	mov edx,OFFSET print_label1
	call WriteString
	mov eax,print_theNumber
	call WriteBin
	call Crlf
	mov edx,OFFSET print_label2
	call WriteString
	mov eax,print_theNumber
	mov ebx,0
	mov edx,0
	mov ecx,32
	LOOP0:
		bt eax,ebx
		jnc UNSETBIT
		inc edx
		UNSETBIT:
		inc ebx
		loop LOOP0
	mov print_bitsSet,edx
	mov eax,edx
	call WriteDec
	call Crlf
	ret
print ENDP
main PROC
	mov edx,OFFSET prompt
	call WriteString
	call ReadInt
	mov print_theNumber,eax
	call print
	mov edx,OFFSET continuelabel
	call WriteString
	WAITLOOP:
		mov eax,5
		call Delay
		call ReadKey
		jz WAITLOOP
	exit
main ENDP
end main