/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** zappy_server
*/

#ifndef ZAPPY_SERVER_H_
    #define ZAPPY_SERVER_H_
    #include "structure.h"

/*Functions*/
void help_usage(int ac, char **av);
int zappy_server(info_serv_t *info);
char *read_socket(int socket_fd, int size);
void free_all(info_serv_t *serv);
void start_clock_client(list_client_t **list);
void check_ia_action(info_serv_t *info);

#endif /* !ZAPPY_SERVER_H_ */
