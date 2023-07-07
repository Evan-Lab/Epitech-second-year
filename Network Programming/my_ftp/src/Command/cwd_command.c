/*
** EPITECH PROJECT, 2023
** myftp
** File description:
** cwd_command
*/

#include "myftp.h"

int check_chdir(client_t *client)
{
    if (chdir(client->str_rest) == -1) {
        write(client->client_fd, "550\n", 4);
        return 1;
    }
    return 0;
}

void splitter(client_t *client)
{
    if (strlen(client->str_rest) == 0)
        write(client->client_fd, "550\n", 4);
    else if (strlen(client->str_rest) != 0 && check_chdir(client) == 0) {
        chdir(client->str_rest);
        write(client->client_fd, "250\n", 4);
    }
}

void cwd_command(client_t *client)
{
    if (client->status == true)
        splitter(client);
    else
        write(client->client_fd, "530\n", 4);
}
