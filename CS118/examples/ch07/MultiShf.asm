TITLE Multiple Doubleword Shift            (MultiShf.asm)

; Demonstration of multi-doubleword shift, using
; SHR and RCR instructions.
; Last update: 06/01/2006

INCLUDE Irvine32.inc

.data
ArraySize = 3
array DWORD ArraySize dup(99999999h)	; 1001 pattern...

.code
main PROC
	
	call ClrScr
	call DisplayArray			; display the array

; Shift the doublewords 1 bit to the right:
	mov esi,0
	shr array[esi+8],1     		; highest dword
	rcr array[esi+4],1     		; middle dword, include Carry flag
	rcr array[esi],1     		; low dword, include Carry flag

	call DisplayArray			; display the array

	exit
main ENDP

;----------------------------------------------------
DisplayArray PROC
;----------------------------------------------------
	pushad

	mov ecx,ArraySize
	mov esi,8
L1:
	mov  eax,array[esi]
	call WriteBin				; display binary bits
	sub  esi,4
	Loop L1
	call Crlf

	popad
	ret
DisplayArray ENDP

END main