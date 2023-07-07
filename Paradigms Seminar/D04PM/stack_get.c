/*
** EPITECH PROJECT, 2023
** day04-afternoon
** File description:
** stack_get
*/

#include "stack.h"
#include "list.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

unsigned int stack_get_size(stack_t stack)
{
    return list_get_size(stack);
}
