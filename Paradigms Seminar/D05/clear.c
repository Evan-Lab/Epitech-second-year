/*
** EPITECH PROJECT, 2023
** day05
** File description:
** clear
*/

#include "string.h"

void clear(string_t *this)
{
    if (this->str != NULL)
        free(this->str);
    this->str = strdup("");
}
