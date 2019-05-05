.model flat

_text segment

; typedef struct il2c_jmp_buf_t
; {
;     uint32_t Edx;
;     uint32_t Ebx;
;     uint32_t Esp;
;     uint32_t Ebp;
;     uint32_t Esi;
;     uint32_t Edi;
;     uint32_t Eip;
; } *il2c_jmp_buf;

; int __fastcall il2c_setjmp(il2c_jmp_buf jb);   // il2c_setjmp(ecx)
@il2c_setjmp proc
    mov [ecx], edx
    mov [ecx+4], ebx
    lea eax, [esp]
    mov [ecx+8], eax  ; Esp
    mov [ecx+12], ebp
    mov [ecx+16], esi
    mov [ecx+20], edi
    mov eax, [esp]
    mov [ecx+24], eax ; Eip (return address)
    xor eax, eax      ; first phase: 0
    ret  
@il2c_setjmp endp

; void __fastcall il2c_longjmp(il2c_jmp_buf jb, int retval);   // il2c_longjmp(ecx, edx)
@il2c_longjmp proc
    mov eax, edx
    mov edx, [ecx]
    mov ebx, [ecx+4]
    mov esp, [ecx+8]
    mov ebp, [ecx+12]
    mov esi, [ecx+16]
    mov edi, [ecx+20]
    mov ecx, [ecx+24] ; Eip (return address)
    jmp ecx
@il2c_longjmp endp

_text ends
end
