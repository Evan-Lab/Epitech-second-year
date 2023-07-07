/*
** EPITECH PROJECT, 2023
** day05
** File description:
** empty
*/

#include "string.h"

int empty(const string_t *this)
{
    if (this->str == NULL || strlen(this->str) == 0)
        return (1);
    else
        return (0);
}
