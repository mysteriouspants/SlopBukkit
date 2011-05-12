TITLE Endless Recursion                        (Endless.asm)

; Last update: 06/01/2006

INCLUDE Irvine32.inc

.data
endlessStr BYTE "This recursion never stops",0

.code
main PROC
	call Endless
	exit
main ENDP

.code
Endless PROC
	mov EDX,offset endlessStr
	call WriteString
	call Endless
	ret				; never reaches this line
Endless ENDP
END main