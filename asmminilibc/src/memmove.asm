BITS 64

section .text
global memmove

memmove:
    cmp rdx, 0
    je end_loop

    xor rcx, rcx
    cmp rdi, rsi
    jae forward_loop

    mov rax, rdi
    add rax, rdx
    sub rax, 1

    mov rbx, rsi
    add rbx, rdx
    sub rbx, 1

    jmp backward_loop

forward_loop:
    jmp write_stack

increment:
    inc rcx

write_stack:
    cmp rcx, rdx
    je read_stack

    movsx rbx, BYTE [rsi+rcx]
    push rbx
    jmp increment

read_stack:
    dec rcx
    pop rbx
    mov BYTE [rdi+rcx], bl
    cmp rcx, 0
    jne read_stack

end_loop:
    mov rax, rdi
    ret

backward_loop:
    dec rcx
    mov bl, BYTE [rbx]
    mov BYTE [rax], bl
    cmp rdi, rax
    jae end_loop
    dec rax
    dec rbx
    jmp backward_loop
