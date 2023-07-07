/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** args
*/

#include "args.h"

int get_number_team(char **av, int ac, int count)
{
    int count_value = 0;

    while (count < ac && av[count][0] != '-') {
        ++count;
        ++count_value;
    }

    return count_value;
}

int get_name(info_serv_t *info, char **av, int ac, int count)
{
    int size;

    if (strcmp(av[count], "-n") != 0)
        return -2;
    ++count;
    size = get_number_team(av, ac, count);
    if (size == 0)
        return -1;
    for (int count_value = 0; count < ac && av[count][0] != '-';
        ++count, ++count_value)
        add_teams(&info->info_game.teams_name, strdup(av[count]), 0);
    info->info_game.nb_teams = size;
    return 0;
}

int get_args(info_serv_t *info_serv, int ac, char **av)
{
    if (ac < 13)
        return -1;
    for (int count = 0; count < ac; ++count) {
        if (get_port(info_serv, av, ac, count) == -1)
            return -1;
        if (get_client_max(info_serv, av, ac, count) == -1)
            return -1;
        if (get_map_width(info_serv, av, ac, count) == -1)
            return -1;
        if (get_map_height(info_serv, av, ac, count) == -1)
            return -1;
        if (get_name(info_serv, av, ac, count) == -1)
            return -1;
        if (get_time_unit(info_serv, av, ac, count) == -1)
            return -1;
    }
    return 0;
}
