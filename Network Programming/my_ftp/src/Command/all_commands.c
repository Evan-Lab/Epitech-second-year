/*
** EPITECH PROJECT, 2023
** myftp
** File description:
** all_commands
*/

#include "myftp.h"

void str_commands_quatro(client_t *client)
{
    if (strcmp(client->str, "HELP") == 0)
        help_command(client);
    else if (strcmp(client->str, "PWD") == 0)
        pwd_command(client);
    else
        str_commands_cinco(client);
}

void str_commands_third(client_t *client)
{
    if (strcmp(client->str, "NOOP") == 0)
        noop_command(client);
    else if (strcmp(client->str, "QUIT") == 0)
        quit_command(client);
    else
        str_commands_quatro(client);
}

void str_commands_second(client_t *client)
{
    if (strcmp(client->str, "PASV") == 0)
        client->socket_data = passv_command(client);
    else if (strcmp(client->str, "RETR") == 0)
        retr_command(client);
    else
        str_commands_third(client);
}

void str_commands(client_t *client)
{
    if (strcmp(client->str, "CWD") == 0)
        cwd_command(client);
    else if (strcmp(client->str, "CDUP") == 0)
        cdup_command(client);
    else
        str_commands_second(client);

}

int all_commands(client_t *client)
{
    client->socket_data = 0;
    if (strcmp(client->str, "USER") == 0)
        user_command(client);
    else if (strcmp(client->str, "PASS") == 0)
        pass_command(client);
    else
        str_commands(client);
    return client->socket_data;
}
