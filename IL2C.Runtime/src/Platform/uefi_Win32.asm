.model flat

_text segment

; .safeseh @il2c_setjmp@4
; .safeseh @il2c_longjmp@8

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
@il2c_setjmp@4 proc
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
@il2c_setjmp@4 endp

; void __fastcall il2c_longjmp(il2c_jmp_buf jb, int retval);   // il2c_longjmp(ecx, edx)
@il2c_longjmp@8 proc
    mov eax, edx
    mov edx, [ecx]
    mov ebx, [ecx+4]
    mov esp, [ecx+8]
    mov ebp, [ecx+12]
    mov esi, [ecx+16]
    mov edi, [ecx+20]
    mov ecx, [ecx+24] ; Eip (return address)
    jmp ecx
@il2c_longjmp@8 endp

; ======================================================================================

; Ported 64bit calculations from:
;   https://gist.github.com/mmozeiko/6a365d6c483fc721b63a#file-win32_crt_math-cpp

; .safeseh __allmul
; .safeseh __aulldiv
; .safeseh __aullrem

; -----------------------------------------------
; _allmul()

ALLMUL_A_LO equ dword ptr [esp + 8]
ALLMUL_A_HI equ dword ptr [esp + 8 + 4]
ALLMUL_B_LO equ dword ptr [esp + 16]
ALLMUL_B_HI equ dword ptr [esp + 16 + 4]

__allmul proc
    push ebx

    mov  eax,ALLMUL_A_HI
    mov  ecx,ALLMUL_B_LO
    mul  ecx             ;eax has AHI, ecx has BLO, so AHI * BLO
    mov  ebx,eax         ;save result

    mov  eax,ALLMUL_A_LO
    mul  ALLMUL_B_HI            ;ALO * BHI
    add  ebx,eax         ;ebx = ((ALO * BHI) + (AHI * BLO))

    mov  eax,ALLMUL_A_LO        ;ecx = BLO
    mul  ecx             ;so edx:eax = ALO*BLO
    add  edx,ebx         ;now edx has all the LO*HI stuff

    pop  ebx

    ret  16              ; callee restores the stack
__allmul endp


; -----------------------------------------------
; _aulldiv()

AULLDIV_DVND_LO equ dword ptr [esp + 12]
AULLDIV_DVND_HI equ dword ptr [esp + 12 + 4]
AULLDIV_DVSR_LO equ dword ptr [esp + 20]
AULLDIV_DVSR_HI equ dword ptr [esp + 20 + 4]

__aulldiv proc
    push    ebx
    push    esi

;
; Now do the divide.  First look to see if the divisor is less than 4194304K.
; If so, then we can use a simple algorithm with word divides, otherwise
; things get a little more complex.
;

    mov     eax,AULLDIV_DVSR_HI     ; check to see if divisor < 4194304K
    or      eax,eax
    jnz     short L1        ; nope, gotta do this the hard way
    mov     ecx,AULLDIV_DVSR_LO     ; load divisor
    mov     eax,AULLDIV_DVND_HI     ; load high word of dividend
    xor     edx,edx
    div     ecx             ; get high order bits of quotient
    mov     ebx,eax         ; save high bits of quotient
    mov     eax,AULLDIV_DVND_LO ; edx:eax <- remainder:lo word of dividend
    div     ecx             ; get low order bits of quotient
    mov     edx,ebx         ; edx:eax <- quotient hi:quotient lo
    jmp     short L2        ; restore stack and return

;
; Here we do it the hard way.  Remember, eax contains DVSRHI
;

L1:
    mov     ecx,eax         ; ecx:ebx <- divisor
    mov     ebx,AULLDIV_DVSR_LO
    mov     edx,AULLDIV_DVND_HI     ; edx:eax <- dividend
    mov     eax,AULLDIV_DVND_LO
L3:
    shr     ecx,1           ; shift divisor right one bit; hi bit <- 0
    rcr     ebx,1
    shr     edx,1           ; shift dividend right one bit; hi bit <- 0
    rcr     eax,1
    or      ecx,ecx
    jnz     short L3        ; loop until divisor < 4194304K
    div     ebx             ; now divide, ignore remainder
    mov     esi,eax         ; save quotient

;
; We may be off by one, so to check, we will multiply the quotient
; by the divisor and check the result against the orignal dividend
; Note that we must also check for overflow, which can occur if the
; dividend is close to 2**64 and the quotient is off by 1.
;

    mul     AULLDIV_DVSR_HI         ; QUOT * AULLDIV_DVSR_HI
    mov     ecx,eax
    mov     eax,AULLDIV_DVSR_LO
    mul     esi             ; QUOT * AULLDIV_DVSR_LO
    add     edx,ecx         ; EDX:EAX = QUOT * DVSR
    jc      short L4        ; carry means Quotient is off by 1

;
; do long compare here between original dividend and the result of the
; multiply in edx:eax.  If original is larger or equal, we are ok, otherwise
; subtract one (1) from the quotient.
;

    cmp     edx,AULLDIV_DVND_HI     ; compare hi words of result and original
    ja      short L4        ; if result > original, do subtract
    jb      short L5        ; if result < original, we are ok
    cmp     eax,AULLDIV_DVND_LO     ; hi words are equal, compare lo words
    jbe     short L5        ; if less or equal we are ok, else subtract
L4:
    dec     esi             ; subtract 1 from quotient
L5:
    xor     edx,edx         ; edx:eax <- quotient
    mov     eax,esi

;
; Just the cleanup left to do.  edx:eax contains the quotient.
; Restore the saved registers and return.
;

L2:
    pop     esi
    pop     ebx

    ret     16
__aulldiv endp

; -----------------------------------------------
; _aullrem()

AULLREM_DVND_LO equ dword ptr [esp + 8]
AULLREM_DVND_HI equ dword ptr [esp + 8 + 4]
AULLREM_DVSR_LO equ dword ptr [esp + 16]
AULLREM_DVSR_HI equ dword ptr [esp + 16 + 4]

__aullrem proc
    push    ebx

; Now do the divide.  First look to see if the divisor is less than 4194304K.
; If so, then we can use a simple algorithm with word divides, otherwise
; things get a little more complex.
;

    mov     eax,AULLREM_DVSR_HI ; check to see if divisor < 4194304K
    or      eax,eax
    jnz     short L1        ; nope, gotta do this the hard way
    mov     ecx,AULLREM_DVSR_LO ; load divisor
    mov     eax,AULLREM_DVND_HI ; load high word of dividend
    xor     edx,edx
    div     ecx             ; edx <- remainder, eax <- quotient
    mov     eax,AULLREM_DVND_LO ; edx:eax <- remainder:lo word of dividend
    div     ecx             ; edx <- final remainder
    mov     eax,edx         ; edx:eax <- remainder
    xor     edx,edx
    jmp     short L2        ; restore stack and return

;
; Here we do it the hard way.  Remember, eax contains DVSRHI
;

L1:
    mov     ecx,eax         ; ecx:ebx <- divisor
    mov     ebx,AULLREM_DVSR_LO
    mov     edx,AULLREM_DVND_HI ; edx:eax <- dividend
    mov     eax,AULLREM_DVND_LO
L3:
    shr     ecx,1           ; shift divisor right one bit; hi bit <- 0
    rcr     ebx,1
    shr     edx,1           ; shift dividend right one bit; hi bit <- 0
    rcr     eax,1
    or      ecx,ecx
    jnz     short L3        ; loop until divisor < 4194304K
    div     ebx             ; now divide, ignore remainder

;
; We may be off by one, so to check, we will multiply the quotient
; by the divisor and check the result against the orignal dividend
; Note that we must also check for overflow, which can occur if the
; dividend is close to 2**64 and the quotient is off by 1.
;

    mov     ecx,eax         ; save a copy of quotient in ECX
    mul     AULLREM_DVSR_HI
    xchg    ecx,eax         ; put partial product in ECX, get quotient in EAX
    mul     AULLREM_DVSR_LO
    add     edx,ecx         ; EDX:EAX = QUOT * DVSR
    jc      short L4        ; carry means Quotient is off by 1

;
; do long compare here between original dividend and the result of the
; multiply in edx:eax.  If original is larger or equal, we're ok, otherwise
; subtract the original divisor from the result.
;
    cmp     edx,AULLREM_DVND_HI ; compare hi words of result and original
    ja      short L4        ; if result > original, do subtract
    jb      short L5        ; if result < original, we're ok
    cmp     eax,AULLREM_DVND_LO ; hi words are equal, compare lo words
    jbe     short L5        ; if less or equal we're ok, else subtract
L4:
    sub     eax,AULLREM_DVSR_LO ; subtract divisor from result
    sbb     edx,AULLREM_DVSR_HI
L5:
;
; Calculate remainder by subtracting the result from the original dividend.
; Since the result is already in a register, we will perform the subtract in
; the opposite direction and negate the result to make it positive.
;
    sub     eax,AULLREM_DVND_LO ; subtract original dividend from result
    sbb     edx,AULLREM_DVND_HI
    neg     edx             ; and negate it
    neg     eax
    sbb     edx,0
;
; Just the cleanup left to do.  dx:ax contains the remainder.
; Restore the saved registers and return.
;
L2:
    pop     ebx
    ret     16

__aullrem endp

_text ends
end
