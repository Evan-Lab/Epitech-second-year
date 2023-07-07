/*
** EPITECH PROJECT, 2023
** day05
** File description:
** at
*/

#include "string.h"

char at(const string_t *this , size_t pos)
{
    size_t len = strlen(this->str);
    if (pos > len)
        return -1;
    return this->str[pos];
}
