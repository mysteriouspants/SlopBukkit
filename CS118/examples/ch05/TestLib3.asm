TITLE Link Library Test #3		(TestLib3.asm)

; Calculate the elapsed time of executing a nested loop
; about 17 billion times.
; Last update: 06/01/2006

INCLUDE Irvine32.inc

OUTER_LOOP_COUNT = 3		; adjust for processor speed
.data
startTime DWORD ?
msg1 BYTE "Please wait...",0dh,0ah,0
msg2 BYTE "Elapsed milliseconds: ",0

.code
main PROC
	mov	edx,OFFSET msg1
	call	WriteString

; Save the starting time.
	call	GetMSeconds
	mov	startTime,eax
	mov	ecx,OUTER_LOOP_COUNT 	

; Perform a busy loop.
L1:	call	innerLoop
	loop	L1

; Display the elapsed time.
	call	GetMSeconds
	sub	eax,startTime
	mov	edx,OFFSET msg2
	call	WriteString
	call	WriteDec
	call	Crlf
	exit
main ENDP

innerLoop PROC
	push	ecx
	mov	ecx,0FFFFFFFFh
L1:	mov	eax,eax
	loop	L1
	pop	ecx
	ret
innerLoop ENDP
END main