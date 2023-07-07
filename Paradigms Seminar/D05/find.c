/*
** EPITECH PROJECT, 2023
** day05
** File description:
** find
*/

#include "string.h"

int find_s(const string_t *this, const string_t *str, size_t pos)
{
    if (this->empty(this) == 1 || pos > strlen(this->str))
        return (-1);
    char *run = strstr((this->str + pos), str->str);
    if (run == NULL)
        return (-1);
    return (int)(run - this->str);
}

int find_c(const string_t *this, const char *str, size_t pos)
{
    if (this->empty(this) == 1 || pos > strlen(this->str))
        return (-1);
    char *run = strstr((this->str + pos), str);
    if (run == NULL)
        return (-1);
    return (int)(run - this->str);
}
