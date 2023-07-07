;
; EPITECH PROJECT, 2023
; Assembly
; File description:
; strrchr.asm
;

section .text
global strrchr ;defini le code executable
strrchr:
xor rax, rax ; initialise registre à 0;
mov rcx, rdi ; copie de rdi dans rcx
mov rdx, 0 ; initialise rdx à 0

loop:
cmp BYTE[rcx], 0 ;cmp compare caractère avec fin de chaine
je end ;si oui, sortir de la boucle
cmp sil, BYTE[rcx] ;test si le caractère est trouvé
jne next_char ;si non, passer à l'adresse suivante
mov rdx, rcx ;sauvegarder l'adresse trouvée
next_char:
inc rcx ;incrémente rcx et regarde à l'adresse suivante
jmp loop ;boucle
end:
mov rax, rdx ;copier l'adresse à retourner sur la pile
ret ;return
