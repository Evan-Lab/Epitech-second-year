/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** get_args
*/

#include <stdlib.h>
#include "args.h"

int get_port(info_serv_t *info, char **av, int ac, int count)
{
    if (strcmp(av[count], "-p") != 0)
        return -2;
    if ((count + 1 < ac) && (check_int(av[count + 1]) == -1))
        return -1;
    info->port = atoi(av[count + 1]);
    return 0;
}

int get_map_width(info_serv_t *info, char **av, int ac, int count)
{
    if (strcmp(av[count], "-x") != 0)
        return -2;
    if ((count + 1 < ac) && (check_int(av[count + 1]) == -1))
        return -1;
    info->info_game.map_width = atoi(av[count + 1]);
    if (info->info_game.map_width < 10 || info->info_game.map_width > 30)
        return -1;
    return 0;
}

int get_map_height(info_serv_t *info, char **av, int ac, int count)
{
    if (strcmp(av[count], "-y") != 0)
        return -2;
    if ((count + 1 < ac) && (check_int(av[count + 1]) == -1))
        return -1;
    info->info_game.map_height = atoi(av[count + 1]);
    if (info->info_game.map_height < 10 || info->info_game.map_height > 30)
        return -1;
    return 0;
}

int get_client_max(info_serv_t *info, char **av, int ac, int count)
{
    list_teams_t *head = info->info_game.teams_name;

    if (strcmp(av[count], "-c") != 0)
        return -2;
    if ((count + 1 < ac) && (check_int(av[count + 1]) == -1))
        return -1;
    if (atoi(av[count + 1]) < 1)
        return -1;
    info->info_game.client_max = atoi(av[count + 1]);
    while (head != NULL) {
        head->teams->nb_connection = atoi(av[count + 1]);
        head = head->next;
    }
    return 0;
}

double get_time_unit(info_serv_t *info, char **av, int ac, int count)
{
    if (strcmp(av[count], "-f") != 0)
        return -2;
    if ((count + 1 < ac) && (check_int(av[count + 1]) == -1))
        return -1;
    info->info_game.time_unit = atoi(av[count + 1]);
    if (info->info_game.time_unit < 2 || info->info_game.time_unit > 10000)
        return -1;
    return 0;
}
