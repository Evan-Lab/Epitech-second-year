/*
** EPITECH PROJECT, 2023
** myftp
** File description:
** reader
*/

#include "myftp.h"

void reader(client_t *client)
{
    client->client_fd = client->fd;
    printf("%s\n", client->buffer);
    client->str = malloc(sizeof(char) * 5);
    client->str = take_first_word(client->buffer);
    client->str_rest = malloc(sizeof(char) * (strlen(client->str) + 1));
    client->str_rest = take_rest(client->buffer, strlen(client->str));
    all_commands(client);
}
