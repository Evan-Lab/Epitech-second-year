/*
** EPITECH PROJECT, 2023
** myftp
** File description:
** login_command
*/

#include "myftp.h"

void cdup_command(client_t *client)
{
    if (client->status == true) {
        write(client->client_fd, "200\n", 4);
        chdir("..");
    } else
        write(client->client_fd, "530\n", 4);
}

void pass_command(client_t *client)
{
    if (client->status == true)
        write(client->client_fd, "230\n", 4);
    else
        write(client->client_fd, "530\n", 4);
}

void user_command(client_t *client)
{
    client->status = true;
    write(client->client_fd, "331\n", 4);
}

void quit_command(client_t *client)
{
    if (client->status == true) {
        write(client->client_fd, "221\n", 4);
        close(client->client_fd);
        exit(0);
    } else
        write(client->client_fd, "530\n", 4);
}
