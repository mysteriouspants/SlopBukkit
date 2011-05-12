TITLE DumpMemory Wrapper Example						(Assignment7.asm)
; Chris Miller, 20100421
; (C) 2010 Chris Miller, All Rights Reserved.
INCLUDE Irvine32.inc
DumpMemory PROTO array:PTR DWORD, arraylength:DWORD, arraytype:DWORD
.data
arr DWORD 00000h, 0000Fh, 000F0h, 000FFh, 00F00h, 00F0Fh, 00FF0h, 00FFFh, 0F000h, 0F00Fh, 0F0F0h, 0F0FFh, 0FF00h, 0FF0Fh, 0FFF0h, 0FFFFh
.code
main PROC
	INVOKE DumpMemory, OFFSET arr,LENGTHOF arr,TYPE arr
	exit
main ENDP
DumpMemory PROC USES ecx esi ebx,array:PTR DWORD, arraylength:DWORD, arraytype:DWORD
	mov esi,array
	mov ecx,arraylength
	mov ebx,arraytype
	call DumpMem
	ret
DumpMemory ENDP
END main