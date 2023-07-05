BITS 64

section .text
global strstr

strstr:
    xor rbx, rbx
    mov r8, rbx
    xor rcx, rcx

loop:
    mov dl, BYTE [rsi+rcx]
    cmp dl, 0
    je return_non_null
    mov al, BYTE [rdi+r8]
    cmp al, 0
    je return_null
    cmp al, dl
    jne increment
    inc r8
    inc rcx
    jmp loop

increment:
    inc rbx
    mov r8, rbx
    xor rcx, rcx
    jmp loop

return_null:
    xor rax, rax
    ret

return_non_null:
    mov rax, rdi
    add rax, rbx
    ret
