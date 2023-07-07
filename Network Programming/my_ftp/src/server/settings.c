/*
** EPITECH PROJECT, 2023
** myftp
** File description:
** settings
*/

#include "myftp.h"

struct sockaddr_in server_settings(client_t *client)
{
    struct sockaddr_in server_addr;
    server_addr.sin_addr.s_addr = INADDR_ANY;

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(client->port);
    if (bind(client->socket_fd, (struct sockaddr *)&server_addr,
        sizeof(server_addr)) == -1) {
        perror("bind()");
        exit(errno);
    }
    return server_addr;
}
