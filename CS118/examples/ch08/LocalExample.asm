TITLE Comparing LOCAL with ENTER-LEAVE   (LocalExample.asm)

; Last update: 06/01/2006

INCLUDE Irvine32.inc

.code
main PROC
	

main ENDP

Example1 PROC
	LOCAL temp:DWORD

	mov	eax,temp

	ret
Example1 ENDP


Example2 PROC
	LOCAL temp:DWORD, SwapFlag:BYTE
	
	mov	eax,temp
	mov	bl,SwapFlag
	
	ret
Example2 ENDP


MySub PROC
     enter 8,0
     
     
     leave
     ret
MySub ENDP


MySub2 PROC
	LOCAL p1:DWORD, p2:DWORD


	
MySub2 ENDP

END main
