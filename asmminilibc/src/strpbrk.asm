BITS 64

section .text
global strpbrk

strpbrk:
    xor rbx, rbx
    jmp loop

increment:
    inc rbx

loop:
    mov al, BYTE [rdi+rbx]
    cmp al, 0
    je end_loop

    xor rcx, rcx
    jmp sub_loop

inc_sub:
    inc rcx

sub_loop:
    mov dl, BYTE [rsi+rcx]
    cmp dl, 0
    je increment

    cmp al, dl
    je ret_non_null

    jmp inc_sub

ret_null:
    xor rax, rax
    jmp end

ret_non_null:
    mov rax, rdi
    add rax, rbx

end_loop:
    ret

end:
    ret
