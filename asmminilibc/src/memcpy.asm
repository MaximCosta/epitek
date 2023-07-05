BITS 64

section .text
global memcpy

memcpy:
    xor rcx, rcx
    cmp rdx, rcx
    je end_loop

loop:
    mov al, BYTE [rsi+rcx]
    mov BYTE [rdi+rcx], al
    inc rcx
    cmp rdx, rcx
    jne loop

end_loop:
    mov rax, rdi
    ret
