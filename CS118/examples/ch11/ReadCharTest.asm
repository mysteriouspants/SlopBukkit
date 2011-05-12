TITLE Testing ReadChar             (ReadCharTest.asm)

; Last update: 06/01/2006

INCLUDE Irvine32.inc

.code
main PROC

	call	ReadChar
	call	DumpRegs

	exit
main ENDP
END main