TITLE Keyboard Toggle Keys             (Keybd.asm)

; This program shows how to detect the states of various
; keyboard toggle keys. Before you run the program, hold
; down a selected key.
; Last update: 06/19/2008

INCLUDE Irvine32.inc
INCLUDE Macros.inc

MSDN says about the return value of GetKeyState:

; If the high-order bit is 1, the key is down; otherwise, it is up.
; If the low-order bit is 1, the key is toggled. A key, such as 
; the CAPS LOCK key, is toggled if it is turned on. The key is off 
; and untoggled if the low-order bit is 0. 

.code
main PROC

	INVOKE GetKeyState, VK_NUMLOCK
	test al,1
	.IF !Zero?
	  mWrite <"The NumLock key is ON",0dh,0ah>
	.ENDIF

	INVOKE GetKeyState, VK_LSHIFT
	call DumpRegs
	test eax,80000000h
	.IF !Zero?
	  mWrite <"The Left Shift key is currently DOWN",0dh,0ah>
	.ENDIF

	exit
main ENDP
END main