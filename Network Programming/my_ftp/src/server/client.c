/*
** EPITECH PROJECT, 2023
** myftp
** File description:
** client
*/

#include "myftp.h"
#include "client.h"

void new_client(struct stock *stock, client_t *client)
{
    stock->client_fd = accept(client->socket_fd,
        (struct sockaddr *)&stock->client_addr, &stock->client_addr_size);
    if (stock->client_fd == -1) {
        perror("accept()");
        exit(errno);
    }
    FD_SET(stock->client_fd, &stock->read_fd);
    if (stock->client_fd > stock->max_fd)
        stock->max_fd = stock->client_fd;
    write(stock->client_fd, "220\n", strlen("220\n"));
}

void listen_clients(struct stock *stock, client_t *client)
{
    client->buffer = malloc(sizeof(char) * 1024);
    int read_size = read(client->fd, client->buffer, 1024);
    if (read_size <= 0) {
        printf("Connection closed on socket %d\n", client->fd);
        close(client->fd);
        FD_CLR(client->fd, &stock->read_fd);
    } else {
        client->buffer[read_size] = '\0';
        reader(client);
    }
}

void my_client(struct stock *stock, client_t *client)
{
    if (FD_ISSET(client->fd, &stock->tmp_fd)) {
        if (client->fd == client->socket_fd)
            new_client(stock, client);
        else
            listen_clients(stock, client);
    }
}
