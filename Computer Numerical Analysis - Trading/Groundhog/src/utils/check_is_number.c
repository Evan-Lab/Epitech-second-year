/*
** EPITECH PROJECT, 2023
** groundhog
** File description:
** check_is_number
*/

#include "groundhog.h"

int check_is_number(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < '0' || str[i] > '9') && str[i] != '\n' && str[i] != '.')
            return 84;
    }
    return 0;
}

int check_is_number_2(char *str)
{
    int i = 0;

    if (str[i] == '-')
        i++;

    for (; str[i] != '\0'; i++) {
        if ((str[i] < '0' || str[i] > '9') && str[i] != '\n' && str[i] != '.')
            return 84;
    }
    return 0;
}
