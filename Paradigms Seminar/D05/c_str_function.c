/*
** EPITECH PROJECT, 2023
** day05
** File description:
** c_str_function
*/

#include "string.h"

const char *c_str(const string_t *this)
{
    if (this->str == NULL)
        return (NULL);
    return (this->str);
}
