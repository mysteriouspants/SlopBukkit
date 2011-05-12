include irvine32.inc
.data
path byte "C:\poke_me.txt",0
msg byte "Folder changed...",0
h handle ?
FILE_NOTIFY_CHANGE_LAST_WRITE equ 10h
FindCloseChangeNotification proto, :handle
WiatForSingleObject proto, :handle, :dword
FindFirstChangeNotificationA proto, :ptr byte, :dword, :dword
INFINITE equ -1
.code
main PROC
	INVOKE FindFirstChangeNotificationA, addr path, false,FILE_NOTIFY_CHANGE_LAST_WRITE
	mov h,eax
	INVOKE WaitForSingleObject, h, INFINITE
	mov edx, offset msg
	call WriteString
	call CrLf
	INVOKE exitProcess,0
main ENDP
end main