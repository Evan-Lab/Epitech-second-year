;
; EPITECH PROJECT, 2023
; Assembly
; File description:
; memmove.asm
;

section .text
global memmove

memmove:
    xor rcx, rcx ; rcx = 0
    cmp rdi, rsi ; compare rdi et rsi, rcs sert à compter le nombre de byte copié et rsi le nombre de byte à copier
    jle loop ; si rdi <= rsi, on va dans loop on copie de gauche à droite
    jmp loop_inverse ; sinon si rsi >= rdi alors on va dans loop_invert on copie de droite à gauche sinon on écrase ce qu'on à part encore copié

loop: ; cette loop sert à copier de gauche à droite
    cmp rdx, 0 ; compare rdx et 0
    je end ; si rdx = 0, on va dans end
    mov r10b, BYTE[rsi + rcx] ; on met dans r10b le byte de rsi + rcx
    mov BYTE[rdi + rcx], r10b ; on met dans le byte de rdi + rcx dans r10b
    dec rdx ; on décrémente rdx
    inc rcx
    jmp loop ; on saute dans loop

loop_inverse: ; cette loop sert à copier de droite à gauche
    cmp rdx, 0 ; compare rdx et 0
    je end ; si rdx = 0, on va dans end
    mov r10b, BYTE[rsi + rdx - 1] ; on met dans r10b le byte de rsi + rdx - 1
    mov BYTE[rdi + rdx - 1], r10b ; on met dans le byte de rdi + rdx - 1 dans r10b
    dec rdx ; on decremente rdx
    jmp loop_inverse ; on revient dans loop_invert

end:
    mov rax, rdi ; met rdi dans rax
    ret ; return