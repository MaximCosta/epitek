BITS 64

section .text
global memset

memset:
    xor rcx, rcx
    cmp rdx, rcx
    je end_loop

loop:
    mov BYTE [rdi+rcx], sil
    inc rcx
    cmp rdx, rcx
    jne loop

end_loop:
    mov rax, rdi
    ret
