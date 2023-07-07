;
; EPITECH PROJECT, 2023
; Assembly
; File description:
; my_strcmp.asm
;

section .text
global strcmp
strcmp:
    xor rcx, rcx ;initialise le registre à 0;
    xor rax, rax ;initialise le registre à 0;

loop:
    cmp BYTE[rdi + rcx], 0 ;compare pour savoir si fin de la chaine (0) ; rcx = compteur
    je modif ;si fin de la chaine, on saute à la fonction modif
    cmp BYTE[rsi + rcx], 0 ;compare pour savoir si fin de la chaine (0)
    je modif ;si fin de la chaine, on saute à la fonction modif
    mov r8b, BYTE[rsi + rcx]
    cmp BYTE[rdi + rcx], r8b ; compare l'octet de rdi et rcx avec le contenue de r8b
    jne modif ;si différent, on saute à la fonction modif
    inc rcx
    jmp loop ;on saute en haut de la boucle

modif: ;nouvelle fonction
    mov al, BYTE[rdi + rcx] ;on met dans al car ah trop petit (registre de 8 bit qui permet de stocker la différence entre deux caractères)
    sub al, BYTE[rsi + rcx] ; sub pour soustraction, on soustrait le caractère de la deuxième chaine qu'on stocke dans al
    movsx rax, al ; on met le résultat dans rax (movsx pour sign extension) qui converti le petit registre en grand registre
    ret ; on retourne le résultat
