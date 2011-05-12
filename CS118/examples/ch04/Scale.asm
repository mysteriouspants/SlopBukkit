TITLE Scaling an Array Index		(Scale.asm)

; Demonstrates the "scaling" feature of array
; indexes. This was not discussed in the book.
; Last update: 06/01/2006

INCLUDE Irvine32.inc

.data
arrayB BYTE  0,1,2,3,4,5
arrayW WORD  0,1,2,3,4,5
arrayD DWORD 0,1,2,3,4,5

.code
main PROC

	mov	esi,4
	mov	al,arrayB[esi*TYPE arrayB]	; 04
	mov	bx,arrayW[esi*TYPE arrayW]	; 0004
	mov	edx,arrayD[esi*TYPE arrayD]	; 00000004
	call	DumpRegs
	exit

main ENDP
END main