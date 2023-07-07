/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** server
*/

#include "zappy_server.h"
#include "server.h"

void get_command_client(info_serv_t *serv, fd_set *list_socket)
{
    int sd = -1;
    int reads = 0;
    list_client_t *head = serv->info_game.list_client;
    char *command;

    while (head != NULL) {
        sd = head->client->socket;
        if (FD_ISSET(sd, list_socket)) {
            ioctl(sd, FIONREAD, &reads);
            command = strdup(read_socket(sd, reads));
            get_command(command, head->client, serv);
            get_command_ai(command, head->client);
            first_connection(head->client, command, serv);
        }
        reads = 0;
        head = head->next;
    }
}

int accept_socket(int fd_socket)
{
    struct sockaddr_in peer_addr;
    socklen_t peer_addr_size = sizeof(struct sockaddr_in);
    int valid_socket = accept(fd_socket, (struct sockaddr *)&peer_addr,
        &peer_addr_size);

    if (valid_socket < 0)
        return -1;
    dprintf(1, "Connection from %s:%u\n", inet_ntoa(peer_addr.sin_addr),
        ntohs(peer_addr.sin_port));
    dprintf(valid_socket, "WELCOME\n");
    return valid_socket;
}

int accept_new_connexion(info_serv_t *serv, fd_set *list_socket)
{
    int client_socket = 0;
    client_t *new_client = malloc(sizeof(client_t));

    if (new_client == NULL)
        return -1;
    if (FD_ISSET(serv->socket, list_socket)) {
        client_socket = accept_socket(serv->socket);
        if (client_socket == -1)
            return -1;
        new_client->first_connection = 1;
        new_client->socket = client_socket;
        add_client(&serv->info_game.list_client, new_client);
    }

    return client_socket;
}

int zappy_server(info_serv_t *serv)
{
    int server_socket = 0;

    create_game_clock(&serv->info_game);
    if ((server_socket = setup_server(serv)) == -1)
        return 84;
    init_things(serv);
    while (1) {
        increment_time(&serv->info_game);
        spawn_ressources_on_game(serv);
        init_sd(serv);
        if (select(FD_SETSIZE, &serv->socket_list, NULL, NULL, NULL) < 0)
            return 84;
        if (accept_new_connexion(serv, &serv->socket_list) == -1)
            return 84;
        get_command_client(serv, &serv->socket_list);
        start_clock_client(&serv->info_game.list_client);
        check_ia_action(serv);
    }
    return 0;
}
