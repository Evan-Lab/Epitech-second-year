/*
** EPITECH PROJECT, 2023
** myftp
** File description:
** file_transfer
*/

#include "myftp.h"

struct sockaddr_in server_settings_data(client_t *client)
{
    int port_data = 3000;
    struct sockaddr_in serv_addr;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_family = AF_INET;
    while (client->result < 0) {
        port_data++;
        serv_addr.sin_port = htons(port_data);
        client->result = bind(client->socket_fd_data,
        (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    }
    client->port1 = port_data / 256;
    client->port2 = port_data % 256;
    char *str = malloc(100);
    sprintf(str, "227 Entering Passive Mode (127,0,0,1,%d,%d)\n",
    client->port1, client->port2);
    write(client->client_fd, str, strlen(str));
    return serv_addr;
}

int passv_command(client_t *client)
{
    client->mode = malloc(sizeof(char) * 5);
    client->mode = "passive";
    client->port1 = 0;
    client->port2 = 0;
    client->result = -1;
    client->socket_fd_data = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv_addr = server_settings_data(client);
    (void)serv_addr;
    return client->socket_fd_data;
}
