BITS 64

section .text
global strchr

strchr:
    push rbp
    mov rbp, rsp
    push rdi

loop:
    cmp BYTE [rdi], sil
    je found
    cmp BYTE [rdi], 0
    je not_found
    inc rdi
    jmp loop

not_found:
    mov rax, 0
    pop rdi
    mov rsp, rbp
    pop rbp
    ret

found:
    mov rax, rdi
    pop rdi
    mov rsp, rbp
    pop rbp
    ret