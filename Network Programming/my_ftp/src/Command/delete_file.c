/*
** EPITECH PROJECT, 2023
** myftp
** File description:
** delete_file
*/

#include "myftp.h"

int check_file(client_t *client)
{
    if (access(client->str_rest, F_OK) == -1) {
        write(client->fd, "550\n", 4);
        return -1;
    }
    return 0;
}

int check_right(client_t *client)
{
    if (access(client->str_rest, W_OK) == -1) {
        write(client->fd, "550\n", 4);
        return -1;
    }
    return 0;
}

int delete_file(client_t *client)
{
    if (check_right(client) == 0 && check_file(client) == 0) {
        remove(client->str_rest);
        write(client->fd, "250\n", 4);
    }
    return 0;
}
