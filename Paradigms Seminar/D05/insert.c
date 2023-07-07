/*
** EPITECH PROJECT, 2023
** day05
** File description:
** insert
*/

#include "string.h"
#include <string.h>

void insert_c(string_t *this, size_t pos, const char *str)
{
    if (pos > strlen(this->str))
        this->append_c(this, str);
    else {
        int i = strlen(this->str) + strlen(str);
        char *time = malloc(sizeof(char) * i + 1);
        strncpy(time, this->str, pos);
        time[pos] = '\0';
        strcat(time, str);
        strcat(time, this->str + pos);
        this->assign_c(this, (const char *)time);
        free(time);
    }
}

void insert_s(string_t *this, size_t pos, const string_t *str)
{
    if (pos > strlen(this->str))
        this->append_s(this, str);
    else {
        int i = strlen(this->str) + strlen(str->str);
        char *time = malloc(sizeof(char) * i + 1);
        strncpy(time, this->str, pos);
        time[pos] = '\0';
        strcat(time, str->str);
        strcat(time, this->str + pos);
        this->assign_c(this, (const char *)time);
        free(time);
    }
}
