/*
** EPITECH PROJECT, 2023
** groundhog
** File description:
** error_checker
*/

#include "groundhog.h"

void not_enought_value(groundhog_t *weather, char *str)
{
    if (strcmp(str, "STOP\n") == 0 && weather->array_size < weather->period) {
        printf("Error: not enought value to compute standard deviation.\n");
        exit(84);
    }
}

void value_checker(char *str)
{
    if (check_is_number_2(str) == 84 && strcmp(str, "STOP\n") != 0) {
        printf("Error: invalid input, a temperature must be a number.\n");
        exit(84);
    }
}

void error_check(groundhog_t *weather, char *str)
{
    not_enought_value(weather, str);
    value_checker(str);
}
