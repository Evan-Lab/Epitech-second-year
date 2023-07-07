/*
** EPITECH PROJECT, 2023
** concat.c
** File description:
** day04
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "concat.h"

void concat_strings(const char *str1, const char *str2, char **res)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int len1 = 0;
    int len2 = 0;
    len1 = strlen(str1);
    len2 = strlen(str2);
    *res = malloc(sizeof(char) * (len1 + len2 + 1));
    while (str1[i] != '\0') {
        (*res)[i] = str1[i];
        i++;
    }
    while (str2[j] != '\0') {
        (*res)[i] = str2[j];
        i++;
        j++;
    }
    (*res)[i] = '\0';
}

void concat_struct(concat_t * str)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int len1 = strlen(str->str1);
    int len2 = strlen(str->str2);
    str->res = malloc(sizeof(char) * (len1 + len2 + 1));
    while (str->str1[i] != '\0') {
        (str->res)[i] = str->str1[i];
        i++;
    }
    while (str->str2[j] != '\0') {
        (str->res)[i] = str->str2[j];
        i++;
        j++;
    }
    (str->res)[i] = '\0';
}
