;
; EPITECH PROJECT, 2023
; Assembly
; File description:
; strchr.asm
;

section .text

global strchr

strchr:
xor rax, rax

loop:
    cmp BYTE[rdi], sil ; compare le caractere de la chaine de caractere avec le caractere a chercher
    je find ; Si trouvé on va dans la nouvelle fonction
    cmp BYTE[rdi], 0 ; compare si fin de chaine de caractere
    je no_find ; Si c'est la fin de la chaine de caractere on va dans la nouvelle fonction
    inc rdi
    jmp loop ; jmp retourn en début de boucle

find:
    mov rax, rdi ; deplace le resultat de rdi dans rax
    ret

no_find:
    mov rax, 0 ; deplace le resultat de 0 dans rax
    ret