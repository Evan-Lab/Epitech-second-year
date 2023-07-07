/*
** EPITECH PROJECT, 2023
** panoramix
** File description:
** error_handling
*/

#include "panoramix.h"

int check_if_number(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return 84;
    }
    return 0;
}

int check_if_more_than_0(char **argv)
{
    if (atoi(argv[1]) <= 0)
        return 84;
    if (atoi(argv[2]) <= 0)
        return 84;
    if (atoi(argv[3]) <= 0)
        return 84;
    if (atoi(argv[4]) <= 0)
        return 84;
    return 0;
}

int check_all_args(char **argv)
{
    if (check_if_number(argv[1]) == 84)
        return 84;
    if (check_if_number(argv[2]) == 84)
        return 84;
    if (check_if_number(argv[3]) == 84)
        return 84;
    if (check_if_number(argv[4]) == 84)
        return 84;
    return 0;
}

int check_args(int argc, char **argv)
{
    if (argc != 5) {
        printf("USAGE: ./panoramix <nb_villagers> <pot_size> <nb_fights> ");
        printf("<nb_refills>\nValues must be >0.\n");
        return 84;
    }
    if (check_all_args(argv) == 84)
        return 84;
    if (check_if_more_than_0(argv) == 84)
        return 84;
    return 0;
}
