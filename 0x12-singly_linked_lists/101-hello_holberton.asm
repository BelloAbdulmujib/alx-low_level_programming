section .data
    hello db 'Hello, Holberton', 10, 0 ; 10 is the ASCII code for a new line (LF)

section .text
    global main

main:
    push rbp
    mov rbp, rsp

    lea rdi, [hello]
    xor eax, eax
    call printf

    mov rsp, rbp
    pop rbp
    ret

