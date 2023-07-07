/*
** EPITECH PROJECT, 2023
** panoramix
** File description:
** main
*/

#include "panoramix.h"

panoramix_t *panoramix;

int take_args(char **argv)
{
    panoramix = malloc(sizeof(panoramix_t));
    panoramix->nb_villagers = atoi(argv[1]);
    panoramix->pot_size = atoi(argv[2]);
    panoramix->nb_fight = atoi(argv[3]);
    panoramix->nb_refills = atoi(argv[4]);
    algorithm();
    return 0;
}

int main(int argc, char **argv)
{
    if (check_args(argc, argv) == 84)
        return 84;
    else
        take_args(argv);
    return 0;
}
