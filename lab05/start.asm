section .text
	
global _start
global read
global write
global open
global close
global strlen

extern main
_start:
	mov ecx,esp
	add ecx,4
	push ecx
	push DWORD[esp+4]
	call	main
        mov     ebx,eax
	mov	eax,1
	int 0x80

read:
	mov eax,3
	mov ebx, [esp+4]
	mov ecx,[esp+8]
	mov edx,[esp+12]
	int 0x80
	ret
write:
	mov eax,4
	mov ebx, [esp+4]
	mov ecx,[esp+8]
	mov edx,[esp+12]
	int 0x80
	ret
open:
	mov eax,5
	mov ebx, [esp+4]
	mov ecx,[esp+8]
	mov edx,[esp+12]
	int 0x80
	ret
close:
	mov eax,6
	mov ebx, [esp+4]
	int 0x80
	ret
strlen:
	push ebp
	mov ebp,esp
	sub esp, 4
	mov eax, DWORD[ebp+8]
	movzx eax, BYTE[eax]
	mov DWORD[ebp-4],0
.L1:
	test al, al
	je .End
	add DWORD[ebp+8], 1
	add DWORD[ebp-4], 1
	mov eax, DWORD[ebp+8]
	movzx eax, BYTE[eax]
	jmp .L1
.End:
	mov eax, DWORD[ebp-4]
	mov esp,ebp
	pop ebp
	ret
	
