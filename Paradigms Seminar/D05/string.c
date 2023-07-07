/*
** EPITECH PROJECT, 2023
** day05
** File description:
** string
*/

#include "string.h"

void string_init(string_t *this, const char *s)
{
    if (s == NULL)
        return;
    this->str = strdup(s);
    this->assign_c = &assign_c;
    this->assign_s = &assign_s;
    this->append_c = &append_c;
    this->append_s = &append_s;
    this->at = &at;
    this->clear = &clear;
    this->lenght = &lenght;
    this->compare_s = &compare_s;
    this->compare_c = &compare_c;
    this->c_str = &c_str;
    this->empty = &empty;
    this->copy = &copy;
    this->insert_c = &insert_c;
    this->insert_s = &insert_s;
    this->to_int = &to_int;
}

void string_destroy(string_t *this)
{
    free(this->str);
}
