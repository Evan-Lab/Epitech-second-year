/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** clean_str
*/

#include "server.h"

char *clean_str(char *str, char remove)
{
    char *new = malloc(sizeof(char) * (strlen(str) + 1));
    int count = 0;
    int count_new = 0;

    while (str[count] != '\0') {
        if (str[count] != remove) {
            new[count_new] = str[count];
            ++count_new;
        }
        ++count;
    }
    new[count_new] = '\0';
    return new;
}
