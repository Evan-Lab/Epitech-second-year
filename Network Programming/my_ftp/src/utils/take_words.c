/*
** EPITECH PROJECT, 2023
** myftp
** File description:
** take_first_word
*/

#include "myftp.h"

char *take_rest(char *str, int nb)
{
    char *str_rest = malloc(sizeof(char) * (strlen(str) - nb + 1));
    int j = 0;
    int other = strlen(str);

    if (str == NULL)
        return NULL;
    if (nb >= other)
        return strdup("");

    for (int i = nb + 1; str[i] != '\0'; i++) {
        if (isalnum(str[i]) || str[i] == '.' || str[i] == '/'
            || str[i] == ':') {
            str_rest[j] = str[i];
            j++;
        }
    }
    str_rest[j] = '\0';
    printf("strlen de str_rest == %ld\n", strlen(str_rest));
    return str_rest;
}

char *take_first_word(char *str)
{
    char *word = malloc(sizeof(char) * (strlen(str) + 1));
    int i = 0;

    for (; str[i] >= 65 && str[i] <= 90; i++)
        word[i] = str[i];
    word[i] = '\0';
    return word;
}
