title x86 asm program using Irvine Library
; Include Files[2]
include irvine32.inc
; Global Variables[3]
.data
	source BYTE "This is the source string",0
	target BYTE SIZEOF source DUP(0)
.code
main proc
	; Copy Source to Target in Reverse[4]
	mov esi, offset source
	mov ecx, sizeof source
	L1:
		mov al, byte ptr [esi]
		mov [target+ecx-2],al
		inc esi
	loop L1
	; Display Memory[5]
	mov edx, offset target
	mov ecx, sizeof target
	dec ecx
	call dumpmem
	exit
main endp
end main
