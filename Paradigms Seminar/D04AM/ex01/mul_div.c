/*
** EPITECH PROJECT, 2023
** mul_div.c
** File description:
** day04
*/

#include <stdio.h>

void mul_div_long (int a, int b, int *mul ,int *div )
{
    *mul = a * b;
    if (b != 0)
        *div = a / b;
    else
        *div = 42;
}

void mul_div_short (int *a, int *b)
{
    int temp = *a;
    *a = *a * *b;
    if (*b != 0)
        *b = temp / *b;
    else
        *b = 42;
}
