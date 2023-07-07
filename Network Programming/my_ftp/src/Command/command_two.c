/*
** EPITECH PROJECT, 2023
** myftp
** File description:
** command_two
*/

#include "myftp.h"

void print_pwd(client_t *client)
{
    FILE *cmdOutput = popen("pwd", "r");

    if (cmdOutput != NULL) {
        char buffer[1024];
        while (fgets(buffer, sizeof(buffer), cmdOutput) != NULL) {
            write(client->client_fd, buffer, strlen(buffer));
        }
        pclose(cmdOutput);
    }
}

void pwd_command(client_t *client)
{
    if (client->status == true) {
        write(client->client_fd, "257\n", 4);
        print_pwd(client);
    } else
        write(client->client_fd, "530\n", 4);
}

void port_command(client_t *client)
{
    if (client->status == true) {
        client->mode = malloc(sizeof(char) * 5);
        client->mode = "active";
        printf("mode: %s\n", client->mode);
        write(client->client_fd, "200\n", 4);
    } else
        write(client->client_fd, "530\n", 4);
}

void dele_command(client_t *client)
{
    if (client->status == true)
        delete_file(client);
    else
        write(client->client_fd, "530\n", 4);
}

void stor_command(client_t *client)
{
    if (client->status == true)
        write(client->client_fd, "150\n", 4);
    else
        write(client->client_fd, "530\n", 4);
}
