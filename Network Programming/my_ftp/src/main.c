/*
** EPITECH PROJECT, 2023
** myftp
** File description:
** main
*/

#include "myftp.h"

int check_param(char *path)
{
    struct stat info;

    if (stat(path, &info)) {
        printf("Directory %s does not exist.\n", path);
        exit(84);
    }
    if (!S_ISDIR(info.st_mode)) {
        printf("%s is not a directory.\n", path);
        exit(84);
    }
    return 0;
}

int take_args(char **argv, client_t *client)
{
    check_param(argv[2]);
    client->status = false;
    client->mode = NULL;
    client->port = atoi(argv[1]);
    client->path = argv[2];
    my_server(client);
    return 0;
}

void man_help(void)
{
    printf("USAGE: ./myftp port path\n");
    printf("\tport is the port number on which");
    printf(" the server socket listens.\n");
    printf("\tpath is the path to the home directory");
    printf("for the Anonymous user.\n");
}

int main(int argc, char **argv)
{
    client_t *client = malloc(sizeof(client_t));
    if (argc == 2 && strcmp(argv[1], "-help") == 0)
        man_help();
    else if (argc == 3 && is_number(argv[1]) == 1)
        take_args(argv, client);
    else
        return 84;
    return 0;
}
