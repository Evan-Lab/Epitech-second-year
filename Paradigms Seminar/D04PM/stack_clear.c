/*
** EPITECH PROJECT, 2023
** day04-afternoon
** File description:
** stack_clear
*/

#include "stack.h"
#include "list.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

void stack_clear(stack_t *stack_ptr)
{
    list_clear(stack_ptr);
}
