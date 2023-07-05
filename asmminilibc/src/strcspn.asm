BITS 64

section .text
global strcspn

strcspn:
    xor rbx, rbx
    jmp .loop

.inc:
    inc rbx

.loop:
    mov al, BYTE [rdi+rbx]
    cmp al, 0
    je .end_loop
    mov rcx, rsi
    call find_char
    test rax, rax
    jnz .end_loop
    jmp .inc

.end_loop:
    mov rax, rbx
    ret

find_char:
    xor rcx, rcx
    jmp .sub_loop

.inc_sub:
    inc rcx

.sub_loop:
    mov dl, BYTE [rcx+rdi]
    cmp dl, 0
    je .ret_null
    cmp dl, BYTE [rcx+rsi]
    je .ret_non_null
    jmp .inc_sub

.ret_null:
    xor rax, rax
    ret

.ret_non_null:
    mov rax, rcx
    ret