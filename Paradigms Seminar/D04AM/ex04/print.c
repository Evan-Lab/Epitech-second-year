/*
** EPITECH PROJECT, 2023
** print.c
** File description:
** CPP POOL
*/

#include <stdio.h>
#include "print.h"

void print_normal(const char *str)
{
    printf("%s\n", str);
}

void print_reverse(const char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    i--;
    while (i >= 0) {
        printf("%c", str[i]);
        i--;
    }
    printf("\n");
}

void print_upper(const char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z')
            printf("%c", str[i] - 32);
        else
            printf("%c", str[i]);
        i++;
    }
    printf("\n");
}

void print_42(const char *str)
{
    printf("42\n");
}

void do_action(action_t action, const char *str)
{
    void (*ptr[4])(const char *) = {print_normal, print_reverse,
    print_upper, print_42};
    ptr[action](str);
}
