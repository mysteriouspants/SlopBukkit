title short program to perform some arbitrary junk for an assignment
; (C) 2010 Chris Miller, All Right Reserved.
; Academic endorsement.
; Created: 20100301

; DONE Use a loop
; DONE Display the accumulated sum of a sequence of integers input by user (use ReadInt)
; DONE Enter zero to end program.
; MAKES NO SENSE Move cursor to approximate middle of screen (use Gotoxy)
; DONE Display the integer and accumulated sum in two columns (use Gotoxy) (use WriteInt)
; DONE Always display the integer prompt above the table of output values (use WriteString)
; SILLY, PUT IT IN MEMORY LIKE A REAL MAN Use symbolic constants wherever possible rather than numeric literals (use EQU or =)
; DONE Display the number of milliseconds the program has been running in the upper right corner of the screen (use GetMSeconds)

include irvine32.inc

.data
	; stuff
	exitToken SDWORD 0			; if this, then exit programme
	accumulator SDWORD ?
	startTime DWORD ?
	
	blanks BYTE "          ",0
	
	header BYTE "~~~ The Amazing Accumulating Machine ~~~          Elapsed time (ms): ",0
	clockrow BYTE 0
	clockcol BYTE 69
	
	prompttxt BYTE "Enter an integer: ",0
	incol BYTE 10
	inrow BYTE 2
	
	incursorcol BYTE 30
	incursorrow BYTE 2
	
	colhead BYTE "Integers:           Accumulated Sum:",0
	colheadrow BYTE 4
	colheadcol BYTE 10
	
	crow BYTE 6
	lcol BYTE 10
	rcol BYTE 30
	
	toomanylinesmsg BYTE "You're having too much fun, and there are too many lines.",0
.code
main proc
	; stuff
	call GetMseconds
	mov startTime,eax
	call Clrscr
	mov edx, OFFSET header
	call WriteString
	
	mov dh,inrow
	mov dl,incol
	call Gotoxy
	mov edx,OFFSET prompttxt
	call WriteString
	
	mov dh,colheadrow
	mov dl,colheadcol
	call Gotoxy
	mov edx,OFFSET colhead
	call WriteString
	
	call GetMaxXY
	movzx eax,dh
	
	mov eax, 0						; put zero into the accumulator
	
	LBEGIN:
		mov accumulator, eax
		
		mov ebx,startTime
		call GetMseconds
		sub eax,ebx
		mov dh,clockrow
		mov dl,clockcol
		call Gotoxy
		call WriteInt
		
		
		mov dh,incursorrow
		mov dl,incursorcol
		call Gotoxy
		mov edx,OFFSET blanks
		call WriteString
		mov dh,incursorrow
		mov dl,incursorcol
		call Gotoxy
		call ReadInt
		mov ebx, eax				; put the read int into ebx where I wanted it
		mov eax, accumulator
		push edx						; about to use edx, save it
		mov edx, exitToken
		cmp ebx, edx
		jz LEND							; exit if input was zero
		pop edx							; restore edx
		xchg eax, ebx
		
		mov dh,crow
		mov dl,lcol
		call Gotoxy
		
		call WriteInt				; write the integer just input
		xchg eax, ebx
		add eax, ebx				; sum
		
		mov dh,crow
		mov dl,rcol
		call Gotoxy
		
		call WriteInt				; write the sum
		
		mov dl,crow
		inc dl
		mov dh,250
		cmp dl,dh
		jz TOOMANYLINES
		
		mov crow,dl
	jmp LBEGIN
	TOOMANYLINES:
	mov dh,crow
	add dh,2
	mov dl,0
	call Gotoxy
	mov edx,OFFSET toomanylinesmsg
	call WriteString
	exit
	LEND:
	mov dh,crow
	mov dl,0
	call Gotoxy
	exit
main endp
end main
