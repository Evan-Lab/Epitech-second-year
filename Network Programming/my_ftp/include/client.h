/*
** EPITECH PROJECT, 2023
** myftp
** File description:
** client
*/

#ifndef CLIENT_H
    #define CLIENT_H

struct stock {
    int client_fd;
    fd_set read_fd;
    fd_set tmp_fd;
    int max_fd;
    struct sockaddr_in client_addr;
    socklen_t client_addr_size;
};

void my_client(struct stock *stock, client_t *client);
void init_struct(struct stock *stock, client_t *client);

#endif /* !CLIENT_H */
