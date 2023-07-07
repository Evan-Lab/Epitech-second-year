/*
** EPITECH PROJECT, 2023
** myftp
** File description:
** open&read
*/

#include "myftp.h"

int retr_command_second(client_t *client, int fd, struct stat sb, char *buffer)
{
    int ret = stat(buffer, &sb);
    if (ret == 0) {
        int buff_size = sb.st_size;
        char *buff = malloc(buff_size);
        if (buff == NULL) {
            perror("Error allocating memory for file buffer");
            return -1;
        }
        ssize_t bytes_read = read(fd, buff, buff_size);
        if (bytes_read < 0) {
            perror("Error reading file");
            free(buff);
            return -1;
        }
        write(client->socket_data, buff, bytes_read);
        write(client->client_fd, "150\n", 4);
        free(buff);
    }
    return 0;
}

int retr_command(client_t *client)
{
    struct stat sb;
    if (client->str_rest == NULL)
        return -1;
    char *buffer = client->path;
    strcat(buffer, "/");
    strcat(buffer, client->str_rest);
    int fd = open(buffer, O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        write(client->client_fd, "150\n", 4);
        return -1;
    }
    retr_command_second(client, fd, sb, buffer);
    return 0;
}
