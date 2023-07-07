/*
** EPITECH PROJECT, 2023
** day05
** File description:
** lenght
*/

#include "string.h"

int lenght(const string_t *this)
{
    if (this->str == NULL)
        return (-1);
    return strlen(this->str);
}
