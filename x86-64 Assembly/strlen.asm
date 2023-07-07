;
; EPITECH PROJECT, 2023
; Assembly
; File description:
; strlen.asm
;
section .text ;defini le code executable
global strlen ;(global) pour indiquer qu'elle peut être appelée par d'autres programmes
strlen: ;nom de ma function
xor rax, rax ;xor initialise le registre xar à 0, il permettra de compter les caractères

loop: ; boucle
    cmp BYTE[rdi + rax], 0
    ;cmp compare rdi (l'adresse de départ de la chaine) et 0 la fin de la chaine de caractères, rax (le compte actuel de caractères, [rdi + rax] est l'adresse de la chaine de caractère
    je endl ;si le caractère est null, on sort de la boucle
    inc rax ;incrémentation de 1 à rax
    jmp loop ;jmp retourne début boucle
endl: ;fin boucle
    ret ;return longueur chaine de caratère