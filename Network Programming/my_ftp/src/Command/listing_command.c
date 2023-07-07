/*
** EPITECH PROJECT, 2023
** myftp
** File description:
** listing_command
*/

#include "myftp.h"

void listing_file(client_t *client)
{
    DIR *dir;
    struct dirent *entry;
    char buffer[1024];
    dir = opendir(".");
    if (dir == NULL) {
        perror("opendir");
        return;
    }
    while ((entry = readdir(dir)) != NULL) {
        sprintf(buffer, "%s\n", entry->d_name);
        write(client->client_fd, buffer, strlen(buffer));
    }
    closedir(dir);
}

void listing_no_mode(client_t *client)
{
    if (client->mode == NULL) {
        write(client->client_fd, "425\n", 4);
        printf("mode: %s\n", client->mode);
        listing_file(client);
        return;
    }
}

void listing_in_mode(client_t *client)
{
    if (strcmp(client->mode, "active") == 0) {
        printf("mode: %s\n", client->mode);
        write(client->client_fd, "150\n", 4);
        listing_file(client);
    }
    if (strcmp(client->mode, "passive") == 0) {
        printf("mode: %s\n", client->mode);
        write(client->client_fd, "150\n", 4);
        listing_file(client);
    }
}

void list_command(client_t *client)
{
    if (client->status == true) {
        listing_no_mode(client);
        if (client->mode != NULL)
            listing_in_mode(client);
    } else
        write(client->client_fd, "530\n", 4);
}
