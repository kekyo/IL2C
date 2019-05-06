.code

_text segment

; typedef struct il2c_jmp_buf_t
; {
;     uint64_t Frame;
;     uint64_t Rbx;
;     uint64_t Rsp;
;     uint64_t Rbp;
;     uint64_t Rsi;
;     uint64_t Rdi;
;     uint64_t R12;
;     uint64_t R13;
;     uint64_t R14;
;     uint64_t R15;
;     uint64_t Rip;
;     uint32_t MxCsr;
;     uint16_t FpCsr;
;     uint16_t Spare;
;     uint128_t Xmm6;
;     uint128_t Xmm7;
;     uint128_t Xmm8;
;     uint128_t Xmm9;
;     uint128_t Xmm10;
;     uint128_t Xmm11;
;     uint128_t Xmm12;
;     uint128_t Xmm13;
;     uint128_t Xmm14;
;     uint128_t Xmm15;
; } *il2c_jmp_buf;

; int il2c_setjmp(il2c_jmp_buf jb);   // il2c_setjmp(rcx)
il2c_setjmp proc
    mov [rcx], rdx      ; Frame
    mov [rcx+8], rbx
    lea r8, [rsp+8]
    mov [rcx+10h], r8   ; Rsp
    mov [rcx+18h], rbp
    mov [rcx+20h], rsi
    mov [rcx+28h], rdi
    mov [rcx+30h], r12
    mov [rcx+38h], r13
    mov [rcx+40h], r14
    mov [rcx+48h], r15
    mov r8, [rsp]
    mov [rcx+50h], r8   ; Rip (return address)
    stmxcsr dword ptr [rcx+58h] ; MxCsr
    fnstcw word ptr [rcx+5ch]   ; FpCsr
    movdqa [rcx+60h], xmm6
    movdqa [rcx+70h], xmm7
    movdqa [rcx+80h], xmm8
    movdqa [rcx+90h], xmm9
    movdqa [rcx+0a0h], xmm10
    movdqa [rcx+0b0h], xmm11
    movdqa [rcx+0c0h], xmm12
    movdqa [rcx+0d0h], xmm13
    movdqa [rcx+0e0h], xmm14
    movdqa [rcx+0f0h], xmm15
    xor eax, eax    ; first phase: 0
    ret  
il2c_setjmp endp

; void il2c_longjmp(il2c_jmp_buf jb, int retval);   // il2c_longjmp(rcx, edx)
il2c_longjmp proc
    mov eax, edx
    mov rdx, [rcx]      ; Frame
    mov rbx, [rcx+8]
    mov rsp, [rcx+10h]  ; Rsp
    mov rbp, [rcx+18h]
    mov rsi, [rcx+20h]
    mov rdi, [rcx+28h]
    mov r12, [rcx+30h]
    mov r13, [rcx+38h]
    mov r14, [rcx+40h]
    mov r15, [rcx+48h]
    mov r8, [rcx+50h]   ; Rip (return address)
    movdqa xmm6, [rcx+60h]
    movdqa xmm7, [rcx+70h]
    movdqa xmm8, [rcx+80h]
    movdqa xmm9, [rcx+90h]
    movdqa xmm10, [rcx+0a0h]
    movdqa xmm11, [rcx+0b0h]
    movdqa xmm12, [rcx+0c0h]
    movdqa xmm13, [rcx+0d0h]
    movdqa xmm14, [rcx+0e0h]
    movdqa xmm15, [rcx+0f0h]
    jmp r8
il2c_longjmp endp

_text ends
end
