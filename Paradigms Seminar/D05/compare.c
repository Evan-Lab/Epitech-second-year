/*
** EPITECH PROJECT, 2023
** day05
** File description:
** compare
*/

#include "string.h"

int compare_s(const string_t *this, const string_t *str)
{
    return strcmp(this->str, str->str);
}

int compare_c(const string_t * this, const char *str)
{
    return strcmp(this->str, str);
}
