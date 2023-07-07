/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-clement.martin
** File description:
** read_socket
*/

#include "server.h"

char *read_socket(int socket_fd, int size)
{
    char *buffer = malloc(sizeof(char) * (size + 1));
    int len = 0;

    len = read(socket_fd, buffer, size);
    if (len == -1) {
        perror("read");
        return "ERROR";
    }
    buffer[len] = '\0';
    return buffer;
}
