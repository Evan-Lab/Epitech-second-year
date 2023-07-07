/*
** EPITECH PROJECT, 2023
** day05
** File description:
** assign
*/

#include "string.h"

void assign_s(string_t *this, const string_t *str)
{
    free(this->str);
    this->str = strdup(str->str);
}

void assign_c(string_t *this, const char *s)
{
    free(this->str);
    this->str = strdup(s);
}
