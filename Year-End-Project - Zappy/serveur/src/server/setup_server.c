/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-clement.martin
** File description:
** setup_server
*/

#include "server.h"
#include "zappy_server.h"

int create_socket(void)
{
    int tcp_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (tcp_socket < 0)
        return -1;
    return tcp_socket;
}

int config_socket(int fd_socket, struct sockaddr_in *conf)
{
    if (bind(fd_socket, (const struct sockaddr *)conf,
        sizeof(struct sockaddr_in)) < 0)
        return -1;
    return 0;
}

int listen_socket(int fd_socket)
{
    if (listen(fd_socket, 42) < 0)
        return -1;
    return 0;
}

void init_sd(info_serv_t *serv)
{
    int sd = 0;
    list_client_t *head = serv->info_game.list_client;

    FD_ZERO(&serv->socket_list);
    FD_SET(serv->socket, &serv->socket_list);

    while (head != NULL) {
        sd = head->client->socket;
        if (sd > 0)
            FD_SET(sd, &serv->socket_list);
        head = head->next;
    }
}

int setup_server(info_serv_t *serv)
{
    struct sockaddr_in conf;
    memset(&conf, 0, sizeof(conf));

    conf.sin_family = AF_INET;
    conf.sin_port = htons(serv->port);
    conf.sin_addr.s_addr = INADDR_ANY;

    if ((serv->socket = create_socket()) == -1)
        return -1;
    if (config_socket(serv->socket, &conf) == -1)
        return -1;
    if (listen_socket(serv->socket) == -1)
        return -1;
    return serv->socket;
}
