/*
** EPITECH PROJECT, 2023
** day05
** File description:
** copy
*/

#include "string.h"

size_t copy(const string_t *this, char *s, size_t n, size_t pos)
{
    size_t value = 0;

    if (this->str == NULL || s == NULL || pos > strlen(this->str))
        return (0);

    for (size_t ma = pos; value < n; ma++) {
        s[value] = this->str[ma];
        value++;
        if (this->str[ma] == '\0')
            return (value);
    }
    return (value);
}
