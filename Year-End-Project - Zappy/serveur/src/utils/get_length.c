/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-clement.martin
** File description:
** get_length
*/

#include <stddef.h>

int get_len_double_char(char **list)
{
    int count = 0;

    while (list[count] != NULL) {
        ++count;
    }
    return count;
}
