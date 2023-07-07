/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** main
*/

#include "zappy_server.h"
#include "args.h"

int main(int ac, char **av)
{
    info_serv_t info;

    help_usage(ac, av);
    info.info_game.teams_name = NULL;
    if (get_args(&info, ac, av) == -1)
        return 84;
    info.info_game.list_client = NULL;
    zappy_server(&info);
    free_all(&info);
    return 0;
}
