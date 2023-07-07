/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** my_itoa
*/

#include "server.h"

char *my_itoa(int value)
{
    char *buffer = malloc(sizeof(char) * 12);
    sprintf(buffer, "%d", value);
    return buffer;
}
