section .data
        text db "hello, world!", 10

section .text
        global _start

_start:
        mov rax, 1      ;sys_write(1, text, 14)
        mov rdi, 1
        mov rsi, text
        mov rdx, 14
        syscall

        mov rax, 60     ;sys_exit(0)
        mov rdi, 0
        syscall
;nasm -f elf64 -o hello.o hello.asm && ld hello.o -o hello.a && hello.a
