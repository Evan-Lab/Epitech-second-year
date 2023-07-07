/*
** EPITECH PROJECT, 2023
** groundhog
** File description:
** main
*/

#include "groundhog.h"

int check_args(int argc, char **argv, groundhog_t *weather)
{
    if (argc == 2 && strcmp(argv[1], "-h") == 0)
        help();
    else if (argc == 2 && check_is_number(argv[1]) == 0) {
        weather->period = atoi(argv[1]);
        my_algorithm(weather);
    } else
        exit(84);
    return 0;
}

int main(int argc, char **argv)
{
    groundhog_t *weather = malloc(sizeof(groundhog_t));
    check_args(argc, argv, weather);
    return 0;
}
