/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** help
*/

#include "zappy_server.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void help_usage(int ac, char **av)
{
    if ((ac == 2 && strcmp(av[1], "-help") == 0) ||
        (ac == 2 && strcmp(av[1], "-h") == 0)) {
        printf("USAGE: ./zappy_server -p port -x width -y height -n name1");
        printf(" name2 ");
        printf("... -c clientsNb -f freq\n");
        printf("\tport\t\tis the port number\n");
        printf("\twidth\t\tis the width of the world\n");
        printf("\theight\t\tis the height of the world\n");
        printf("\tnameX\t\tis the name of the team X\n");
        printf("\tclientsNb\tis the number of authorized clients per team\n");
        printf("\tfreq\t\tis the reciprocal of time unit for execution of");
        printf("actions\n");
        exit(0);
    }
}

int print_info(info_serv_t *info)
{
    list_teams_t *head = info->info_game.teams_name;

    printf("port: %d\n", info->port);
    printf("client max: %d\n", info->info_game.client_max);
    printf("map width: %d, map height: %d\n", info->info_game.map_width,
        info->info_game.map_height);
    printf("time unit: %d\n", info->info_game.time_unit);
    printf("nb teams: %d\n", info->info_game.nb_teams);
    while (head != NULL) {
        printf("teams name: %s\n", head->teams->name);
        head = head->next;
    }
    return 0;
}
