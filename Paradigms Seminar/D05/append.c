/*
** EPITECH PROJECT, 2023
** day05
** File description:
** append
*/

#include "string.h"

void append_s(string_t *this, const string_t *ap)
{
    this->str = realloc(this->str, (strlen(this->str) + strlen(ap->str) + 1));
    this->str = strcat(this->str, ap->str);
}

void append_c(string_t *this, const char *ap)
{
    this->str = realloc(this->str, (strlen(this->str) + strlen(ap) + 1));
    this->str = strcat(this->str, ap);
}
