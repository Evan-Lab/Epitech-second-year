/*
** EPITECH PROJECT, 2023
** myftp
** File description:
** server
*/

#include "myftp.h"
#include "client.h"

void init_struct(struct stock *stock, client_t *client)
{
    stock->client_fd = 0;
    stock->max_fd = client->socket_fd;;
    stock->client_addr_size = sizeof(stock->client_addr);
}

int server_loop(client_t *client)
{
    struct stock *stock = malloc(sizeof(struct stock));
    init_struct(stock, client);
    FD_ZERO(&stock->read_fd);
    FD_SET(client->socket_fd, &stock->read_fd);

    printf("WAITING FOR INCOMING CONNECTION\n");
    while (1) {
        stock->tmp_fd = stock->read_fd;
        if (select(stock->max_fd + 1, &stock->tmp_fd,
            NULL, NULL, NULL) == -1) {
            perror("select");
            exit(errno);
        }
        for (client->fd = 0; client->fd <= stock->max_fd; client->fd++)
            my_client(stock, client);
    }
    return 0;
}

int my_server(client_t *client)
{
    client->socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_address = server_settings(client);
    (void)server_address;
    if (listen(client->socket_fd, 10) == -1) {
        perror("listen full");
        exit(84);
    }
    server_loop(client);
    return 0;
}
