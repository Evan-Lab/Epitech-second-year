/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** check
*/

#include <stdlib.h>

int check_int(char *str)
{
    for (int count = 0; str[count] != '\0'; ++count) {
        if (str[count] < '0' || str[count] > '9')
            return -1;
    }
    return 0;
}

int check_float(char *str)
{
    char *end_ptr;

    strtod(str, &end_ptr);
    if (*end_ptr != '\0')
        return -1;
    return 0;
}
