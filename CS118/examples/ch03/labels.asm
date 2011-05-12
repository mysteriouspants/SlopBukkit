TITLE (labels.asm)

; Last update: 06/01/2006

INCLUDE Irvine32.inc

.data
bval BYTE 1
wval WORD 2
dval DWORD 3

myTax	DWORD 5000

.code
main PROC

	movzx eax,dval

L1:

	exit
main ENDP

second PROC



L1:


second ENDP

END main