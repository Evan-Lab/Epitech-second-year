;
; EPITECH PROJECT, 2023
; Assembly
; File description:
; memset.asm
;

section .text
global memset

memset:
    xor rcx, rcx ; initialise le registre à 0
    xor rax, rax ; initialise le registre à 0
    mov r10, rdi ; copie de rdi dans r10

loop:
    cmp rcx, rdx
    jge end ; jump if greater or equal /si rcx >= rdx, on sort de la boucle
    mov BYTE[rdi], sil ; on copie sil dans le registre rdi
    inc rcx
    inc rdi
    jmp loop ; retour a la boucle

end: ; c'est la fin
    mov rax, r10 ; on copie r10 dans rax
    ret