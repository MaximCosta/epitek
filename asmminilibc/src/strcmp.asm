section .text
global strcmp

strcmp:
    mov rax, rdi
    mov rbx, rsi
loop:
    mov dl, byte [rax]
    mov cl, byte [rbx]
    cmp dl, cl
    jne done
    cmp dl, 0
    je done
    inc rax
    inc rbx
    jmp loop
done:
    movzx eax, byte [rax]
    movzx ebx, byte [rbx]
    sub eax, ebx
    ret
