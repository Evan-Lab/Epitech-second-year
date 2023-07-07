/*
** EPITECH PROJECT, 2023
** myftp
** File description:
** is_number
*/

#include "myftp.h"

int is_number(char *str)
{
    if (*str == '\0')
        return 0;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < '0' || str[i] > '9')
            return 0;
    return 1;
}
