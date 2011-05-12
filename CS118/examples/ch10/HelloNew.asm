TITLE Macro Functions            (HelloNew.asm)

; Shows how to use macros to configure
; a program to run on multiple platforms.
; Use the makeHello16.bat file (in the current directory)
; to assemble this program for a Real-mode target.
; Alternatively, use the c:\Masm615\make32.bat file to
; assemble the program.

; Last update: 8/16/01.

INCLUDE Macros.inc
IF IsDefined( RealMode )
	INCLUDE Irvine16.inc
ELSE
	INCLUDE Irvine32.inc
ENDIF

.code
main PROC
	Startup

	mWrite <"This program can be assembled to run ",0dh,0ah>
	mWrite <"in both Real mode and Protected mode.",0dh,0ah>

	exit
main ENDP
END main