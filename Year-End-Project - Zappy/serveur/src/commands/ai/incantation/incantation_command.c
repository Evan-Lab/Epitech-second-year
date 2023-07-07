/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-clement.martin
** File description:
** incantation_command
*/

#include "incantation.h"

void incantation_command(client_t *client, info_game_t *info, char *args)
{
    (void)args;
    if (client->incantation_level == 7)
        incantation_level_8(client, info);
    if (client->incantation_level == 6)
        incantation_level_7(client, info);
    if (client->incantation_level == 5)
        incantation_level_6(client, info);
    if (client->incantation_level == 4)
        incantation_level_5(client, info);
    if (client->incantation_level == 3)
        incantation_level_4(client, info);
    if (client->incantation_level == 2)
        incantation_level_3(client, info);
    if (client->incantation_level == 1)
        incantation_level_2(client, info);
}
