title finds whether numbers are prime
; (C) 2010 Chris Miller, Aw richts pitten by.
; Academic endorsement.
; Created: 20100410

.586
.model flat,C

.code
isPrime_asm PROTO, num:DWORD

isPrime_asm PROC, num:DWORD
	LOCAL tmp:DWORD, ctrlWord:WORD
	FINIT
	FILD num
	FSTCW ctrlWord
	OR ctrlWord,110000000000b
	FLDCW ctrlWord
	FSQRT								; sqrt(n)
	FIST tmp
	MOV ESI,tmp
	MOV EAX,1
	CMP ESI,EAX
	JNE L1
	MOV AL,1
	RET
	L1:
		MOV EAX,num
		CDQ
		MOV EBX,ESI
		IDIV EBX
		MOV EBX,0
		CMP EDX,EBX
		JNE L1E
		MOV AL,0						; if the remainder is zero, then it's not prime
		RET
		L1E:
		DEC ESI
		MOV EAX,1
		CMP ESI,EAX
		JG L1
	MOV AL,1
	RET
isPrime_asm ENDP
END
