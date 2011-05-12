title finds whether numbers are prime
; (C) 2010 Chris Miller, Aw richts pitten by.
; Academic endorsement.
; Created: 20100410
include irvine32.inc
.data
	prompt BYTE "Enter an integer, or zero to exit: ",0
	bye BYTE "Bye!",0
	preconditionFail BYTE "Failed precondition, must be greater than 1",0
	noprime BYTE "Not prime, running time: ",0
	yesprime BYTE "Is a prime, running time: ",0
	ctrlWord WORD ?
	startTime DWORD ?
	endTime DWORD ?
.code
primetestShell PROC
	MOV EBX,1
	CMP EAX,EBX
	JBE PRECONDNOTMET
	PUSH EAX
	CPUID
	RDTSC
	MOV startTime,EAX
	POP EAX
	CALL primetest
	JNZ NOTPRIME
	PRIME:
		MOV EDX,OFFSET yesprime
		JMP SHELLEND
	NOTPRIME:
		MOV EDX,OFFSET noprime
		JMP SHELLEND
	PRECONDNOTMET:
		MOV EDX,OFFSET preconditionFail
		JMP SHELLEND
	SHELLEND:
		CALL WriteString
		CPUID
		RDTSC
		MOV EBX,startTime
		SUB EAX,EBX
		CALL WriteInt
		CALL Crlf
		RET
primetestShell ENDP
; finds whether a number in EAX is prime or not
; returns 0 in EAX for false, 1 for true
primetest PROC
	LOCAL n:DWORD, tmp:DWORD
	MOV n,EAX							; n is now the number to test
	FILD n
	FSQRT								; sqrt(n)
	FISTP tmp
	MOV ECX,tmp
	MOV EAX,1
	CMP ECX,EAX
	JNE L1
	MOV AH,01000000b
	SAHF								; set ZF
	RET
	DEC ECX
	L1:
		MOV EAX,n
		MOV EBX,ECX
		INC EBX
		CDQ
		IDIV EBX
		CMP EDX,0
		JNZ L1E
		MOV AH,00000000b
		SAHF								; reset ZF
		RET
		L1E:
		LOOP L1
	MOV AH,01000000b
	SAHF								; set ZF
	RET
primetest ENDP
; finds the greatest common divisor of the two integers
; in EAX and EBX.  puts the result in EAX
gcd PROC								; a,b
	LOCAL a:DWORD, b:DWORD
	MOV a,EAX
	MOV b,EBX
	MOV ECX,0
	CMP EAX,ECX
	JNZ SKIP1
	MOV EAX,EBX
	RET
	SKIP1:
	CMP EBX,ECX
	JNZ SKIP2
	RET									; gcd(a,0) = a						
	SKIP2:
										; gcd(a,b) = gcd(b,a-b*floor(a/b))
	MOV EAX,a
	CDQ
	MOV EBX,b
	IDIV EBX							; EAX = floor(a/b) (EDX is remainder)
	MOV EBX,b
	IMUL EAX,EBX						; EAX = b*floor(a/b)
	MOV EBX,a
	SUB EBX,EAX							; EBX = a-b*floor(a/b)
	MOV EAX,b
	CALL gcd
	RET
gcd ENDP
precondFail PROC
	MOV EDX,OFFSET preconditionFail
	CALL WriteString
	CALL Crlf
precondFail ENDP
main PROC
	FINIT 								; initialise FPU
	FSTCW ctrlWord
	OR ctrlWord,110000000000b
	FLDCW ctrlWord
	PSTART:
		MOV EDX,OFFSET prompt
		CALL WriteString 				; write the prompt string
		CALL ReadInt 	 				; read the integer
		MOV EBX,0000h
		CMP EAX,EBX
		JZ PEND							; compare the integer to zero, 
										; and if it is, jump to the
										; programme end
		PUSH EAX
		CALL primetestShell				; push the argument and call the
										; primality test routine
		POP EAX
		JMP PSTART
	PEND:
		MOV EDX,OFFSET bye
		CALL WriteString				; end of the programme
		EXIT
main ENDP
END main
