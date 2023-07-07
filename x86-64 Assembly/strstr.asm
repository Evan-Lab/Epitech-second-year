;
; EPITECH PROJECT, 2023
; Assembly
; File description:
; strstr.asm
;

section .text
global strstr

strstr:
    xor rax, rax ; rax = 0
    cmp BYTE[rsi], 0 ; compare si rsi à 0 et si la chaine est vide
    je end_str ; si la chaine est vide on saute à end_str
    mov BYTE r8b, [rsi] ; on met le premier caractère de rsi dans r8b
    jmp loop ; on saute à loop

search_str:
    mov r9b, BYTE[rsi + rbx] ; on met le caractère suivant de rsi dans r9b
    cmp r9b, 0 ; on compare si r9b est égale à 0
    je end_str ; si r9b est égale à 0 on saute à end_str
    cmp r9b, BYTE[rdi + rcx] ; on compare si r9b est égale au caractère suivant de rdi
    jne function ; si r9b est différent du caractère suivant de rdi on saute à function
    inc rcx ;rcx++
    inc rbx ;rbx++
    jmp search_str ; on saute à search_str

function:
    inc rdi ;rdi++
    jmp loop ; on saute à loop

loop:
    mov r8b, BYTE[rsi] ; on met le premier caractère de rsi dans r8b
    cmp byte [rdi], 0 ; on compare si le caractère suivant de rdi est égale à 0
    je end ; si le caractère suivant de rdi est égale à 0 on saute à end
    xor rcx, rcx
    xor rbx, rbx
    cmp r8b, BYTE[rdi] ; on compare si r8b est égale au caractère suivant de rdi
    jne function ; si r8b est différent du caractère suivant de rdi on saute à function
    jmp search_str ; on saute à search_str

end_str: ;function end
    mov rax, rdi ; on met rdi dans rax
    ret ;return

end:
    ret ;return