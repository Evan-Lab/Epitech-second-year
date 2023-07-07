/*
** EPITECH PROJECT, 2023
** myftp
** File description:
** other_commands
*/

#include "myftp.h"

void noop_command(client_t *client)
{
    write(client->client_fd, "200\n", 4);
}

void help_command(client_t *client)
{
    write(client->client_fd, "214\n", 4);
}
