/*
** EPITECH PROJECT, 2023
** day05
** File description:
** to_int
*/

#include "string.h"

int to_int(const string_t *this)
{
    return (atoi(this->str));
}
