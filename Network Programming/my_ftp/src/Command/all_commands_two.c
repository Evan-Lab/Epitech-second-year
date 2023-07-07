/*
** EPITECH PROJECT, 2023
** myftp
** File description:
** all_commands_two
*/

#include "myftp.h"

void str_commands_seis(client_t *client)
{
    if (strcmp(client->str, "STOR") == 0)
        stor_command(client);
    else if (strcmp(client->str, "DELE") == 0)
        dele_command(client);
    else
        write(client->client_fd, "500\n", 4);
}

void str_commands_cinco(client_t *client)
{
    if (strcmp(client->str, "LIST") == 0)
        list_command(client);
    else if (strcmp(client->str, "PORT") == 0)
        port_command(client);
    else
        str_commands_seis(client);
}
