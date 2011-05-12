TITLE               (TestGetCommandTail.asm)

; Calls GetCommandtail from the Irvine32 library.
; Last update: 06/01/2006

INCLUDE Irvine32.inc
INCLUDE Macros.inc
.data
cmdTail BYTE 129 DUP(0)			; empty buffer
.code
main PROC
     mov    edx,OFFSET cmdTail
     call   GetCommandtail 		; fills the buffer
     jc     L1
     mWrite "Carry flag is not set"
     jmp    L2
L1:
     mWrite "Carry flag is set"
L2:
     call   CRLF
     call   writeString
     call   CRLF
     
     exit
main ENDP

END main