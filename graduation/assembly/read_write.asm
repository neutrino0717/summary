section .data
        text1 db "What is your name: "  ;define bytes
        text2 db "Hello, "

section .bss
        name resb 16    ;reserve bytes
section .text
        global _start

_start:
        call _printText1
        call _getName
        call _printText2
        call _printName

        mov rax, 60     ;sys_exit(0)
        mov rdi, 0      ;exit status 0
        syscall

_getName:
        mov rax, 0      ;sys_read(0, name, 16)
        mov rdi, 0      ;standard input
        mov rsi, name   ;store input to name
        mov rdx, 16
        syscall
        ret

_printName:
        mov rax, 1      ;sys_write(1, name, 14)
        mov rdi, 1      ;standard output
        mov rsi, name   ;"neutrino"
        mov rdx, 16     ;size of name
        syscall
        ret

_printText1:
        mov rax, 1      ;sys_write(1, text1, 19)
        mov rdi, 1      ;standard output
        mov rsi, text1  ;"what's your name?"
        mov rdx, 19     ;size of text1
        syscall
        ret


_printText2:
        mov rax, 1      ;sys_write(1, text, 7)
        mov rdi, 1      ;standard output
        mov rsi, text2  ;"Hello, "
        mov rdx, 7     ;size of text1
        syscall
        ret
        
;nasm -f elf64 read_write.asm -o read_write.o && ld read_write.o -o read_write.a && read_write.a
