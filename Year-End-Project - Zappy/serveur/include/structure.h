/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** structure
*/

#ifndef STRUCTURE_H_
    #define STRUCTURE_H_

    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <netinet/ip.h>
    #include <arpa/inet.h>
    #include <sys/select.h>
    #include <time.h>

typedef struct client_s client_t;
typedef struct info_game_s info_game_t;

typedef enum type_client {
    GUI,
    AI,
    None,
} type_client;

typedef struct ressources_s {
    char *name;
    int quantity;
} ressources_t;

typedef struct clock_client_s {
    time_t startTime;
    int seconds;
} clock_client_t;

typedef struct ia_action_s {
    char *name;
    void (*function)(client_t *client, info_game_t *info, char *args);
    double time;
    char *args;
    int status;
} ia_action_t;

typedef struct list_action_s {
    ia_action_t *action;
    struct list_action_s *next;
} list_action_t;

typedef struct clock_struct_s {
    time_t startTime;
    int seconds;
} clock_struct_t;

typedef struct egg_s {
    int x;
    int y;
    int available;
    int id;
} egg_t;

typedef struct list_egg_s {
    egg_t *egg;
    struct list_egg_s *next;
} list_egg_t;

typedef struct teams_s {
    char *name;
    int nb_connection;
    list_egg_t *list_egg;
} teams_t;

typedef struct list_teams_s {
    teams_t *teams;
    struct list_teams_s *next;
} list_teams_t;

typedef struct client_s {
    int socket;
    int number_client;
    int first_connection;
    int x;
    int y;
    int incantation_level;
    int incantaion_in_progress;
    char *team_name;
    char *orientation_player;
    double life;
    clock_client_t *client_clock;
    clock_struct_t *timer;
    type_client type;
    ressources_t inventory[7];
    list_action_t *action;
} client_t;

typedef struct list_client_s {
    client_t *client;
    struct list_client_s *next;
} list_client_t;

typedef struct map_s {
    client_t *client;
    ressources_t *ressources;
    int egg;
    egg_t *eggs;
} map_t;

typedef struct info_game_s {
    int map_width;
    int map_height;
    int time_unit;
    int client_max;
    int nb_teams;
    map_t **map;
    clock_struct_t *timer;
    list_teams_t *teams_name;
    list_client_t *list_client;
    ressources_t ressources[7];
} info_game_t;

typedef struct info_serv_s {
    int port;
    int socket;
    fd_set socket_list;
    info_game_t info_game;
} info_serv_t;

#endif /* !STRUCTURE_H_ */
