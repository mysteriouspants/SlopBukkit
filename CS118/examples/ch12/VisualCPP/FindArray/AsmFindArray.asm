TITLE FindArray Procedure      (AsmFindArray.asm)

; This version uses hand-optimized assembly language 
; code with the SCASD instruction. 

.586
.model flat,C

AsmFindArray PROTO,
	srchVal:DWORD, arrayPtr:PTR DWORD, count:DWORD

.code
;-----------------------------------------------
AsmFindArray PROC USES edi,
	srchVal:DWORD, arrayPtr:PTR DWORD, count:DWORD
;
; Performs a linear search for a 32-bit integer
; in an array of integers. Returns a boolean 
; value in AL indicating if the integer was found.
;-----------------------------------------------
	true = 1
	false = 0

 	mov	eax,srchVal    	; search value
 	mov	ecx,count      	; number of items
 	mov	edi,arrayPtr   	; pointer to array

 	repne	scasd           	; do the search
 	jz	returnTrue      	; ZF = 1 if found

returnFalse:             
     mov	al,false     
     jmp	short exit

returnTrue:
     mov	al, true

exit:	
	ret   
AsmFindArray ENDP

END

