TITLE Conditional Jumps             (jumps2.asm)

; Demonstrates conditional jumps
; Last update: 06/01/2006

INCLUDE IRVINE32.inc
INCLUDE macros.inc

.data
myData DWORD 50 DUP(0)

.code
main PROC

	jz L1

	mDumpMem myData,50,4
	mDumpMem myData,50,4
	mDumpMem myData,50,4
	mDumpMem myData,50,4
	mDumpMem myData,50,4
	mDumpMem myData,50,4
	mDumpMem myData,50,4

L1:         

	exit
main ENDP

END main