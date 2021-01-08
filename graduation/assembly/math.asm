section .data
        ;text1 db "What is your name: "  ;define bytes
        digit db 0,10    ;0, 10 which is newline in ascii

;section .bss
;        name resb 16    ;reserve bytes
section .text
        global _start

_start:
        mov rax, 9      ;####this program is to print 9#####
        call _printRAXDigit

        mov rax, 60     ;sys_exit(0)
        mov rdi, 0      ;exit status 0
        syscall

_printRAXDigit:
        add rax, 48     ;48 + 9 = 57, which is the ascii code for 9
        mov [digit], al ;the lower byte of rax register moved to memory address of digit
                        ;aka 57(small that 255) to [digit], result in "digit db 57,10"
                        ;note: digit is defined with two bytes:0,10. 10 is newline
;4-bit register | Lower 32 bits | Lower 16 bits | Lower 8 bits
;rax            | eax           | ax            | al
        mov rax, 1      ;standard input
        mov rdi, 1      ;store input to name
        mov rsi, digit  ;text buffer
        mov rdx, 2      ;size
        syscall
        ret
        
;f=math; nasm -f elf64 $f.asm -o ${f}.o && ld $f.o -o $f.a && $f.a
