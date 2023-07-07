;
; EPITECH PROJECT, 2023
; Assembly
; File description:
; strncmp.asm
;

section .text
global strncmp
strncmp:
    xor rcx, rcx
    xor rax, rax

loop:
    cmp rcx, rdx
    je function ;jump à function
    cmp BYTE[rsi + rcx], 0 ;regarde si on a atteint la fin de la chaine de caractère
    je function
    cmp BYTE[rsi + rcx], 0 ;regarde si on à atteint la fin de la chaine de caractère
    je function
    mov r10b, BYTE[rsi, rcx] ;charge le premier caractère dans r10b
    cmp BYTE[rdi, rcx], r10b
    jne function ; on saute à function si les caractères sont différents
    inc rcx
    jmp loop ; jump au début de loop
function:
    mov al, BYTE[rdi + rcx] ;charge le caractère de la chaine 2 dans ah
    sub al, BYTE[rsi, rcx] ; soustrait le caractère de la chaine 1 à celui de la chaine 2
    movsx rax, al ; met le résultat dans de al dans rax
    ret ;return rax
