;
; EPITECH PROJECT, 2023
; Assembly
; File description:
; memcpy.asm
;

section .text
global memcpy
memcpy:

xor rcx, rcx ;initalise le registre à 0
xor rax, rax ;initalise le registre à 0
mov r8, rdi ; copie de rdi dans r9

loop: ;boucle
    cmp rcx, rdx
    je end ; si rcx = rdx alors stop
    mov r9b, BYTE[rsi] ; copie de BYTE[rsi] dans r9b, copie d'un byte de rsi dans r9b
    mov BYTE[rdi], r9b
    inc rcx
    inc rdi
    inc rsi
    jmp loop ; retour au début de la boucle

end: ; fin de la boucle
    mov rax, r8 ; copie de r8 dans rax
    ret ; retour à la fonction