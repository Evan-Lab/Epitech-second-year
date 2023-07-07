/*
** EPITECH PROJECT, 2023
** myftp
** File description:
** myftp
*/

#ifndef MYFTP_H_
    #define MYFTP_H_
    #include <string.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <errno.h>
    #include <arpa/inet.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <pthread.h>
    #include <stdio.h>
    #include <sys/select.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <stdbool.h>
    #include <dirent.h>
    #include <ctype.h>

/*Struct*/

typedef struct client_s {
    char *path;
    int port;
    int socket_fd;
    int client_fd;
    int read_size;
    int temp;
    char *buffer;
    int socket_data;
    int socket_fd_data;
    int port1;
    int port2;
    int result;
    char *str;
    int fd;
    char *str_rest;
    bool status;
    char *mode;
} client_t;

/*server*/

int my_server(client_t *client);
void reader(client_t *client);
struct sockaddr_in server_settings(client_t *client);

/*utils*/

char *take_first_word(char *str);
char *take_rest(char *str, int nb);
int is_number(char *str);

/*Login command*/

int all_commands(client_t *client);
void str_commands_cinco(client_t *client);
void user_command(client_t *client);
void pass_command(client_t *client);
void cwd_command(client_t *client);
void cdup_command(client_t *client);
int passv_command(client_t *client);
void noop_command(client_t *client);
void quit_command(client_t *client);
void help_command(client_t *client);
void pwd_command(client_t *client);
int retr_command(client_t *client);
void list_command(client_t *client);
void stor_command(client_t *client);
void dele_command(client_t *client);
void port_command(client_t *client);
int delete_file(client_t *client);
#endif
