/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-clement.martin
** File description:
** command
*/

#ifndef COMMAND_H_
    #define COMMAND_H_

    #include "structure.h"

/*Struct for server commands*/
typedef struct commands_s {
    char *command;
    void (*function)(client_t *client, info_serv_t *serv, char **args);
} command_t;

/*Calling server commands*/
void msz_command(client_t *client, info_serv_t *serv, char **arg);
void sgt_command(client_t *client, info_serv_t *serv, char **arg);
void tna_command(client_t *client, info_serv_t *serv, char **arg);
void mct_command(client_t *client, info_serv_t *serv, char **arg);
void sst_command(client_t *client, info_serv_t *serv, char **args);
void btc_command(client_t *client, info_serv_t *serv, char **args);
void ppo_command(client_t *client, info_serv_t *serv, char **args);
void plv_command(client_t *client, info_serv_t *serv, char **args);
void pin_command(client_t *client, info_serv_t *serv, char **args);

/*server commands*/
static const command_t commands[] = {
    {"msz", &msz_command},
    {"sgt", &sgt_command},
    {"tna", &tna_command},
    {"sst", &sst_command},
    {"mct", &mct_command},
    {"bct", &btc_command},
    {"ppo", &ppo_command},
    {"plv", &plv_command},
    {"pin", &pin_command},
    {NULL, NULL}
};

/*Struct for ia commands*/
typedef struct ia_commands_s {
    char *command;
    void (*function)(client_t *client, info_game_t *info, char *args);
    double time;
} ia_command_t;

/*Calling ia commands*/
void forward_command(client_t *client, info_game_t *info, char *args);
void right_command(client_t *client, info_game_t *info, char *args);
void left_command(client_t *client, info_game_t *info, char *args);
void look_command(client_t *client, info_game_t *info, char *args);
void connect_nbr_commad(client_t *client, info_game_t *info, char *args);
void incantation_command(client_t *client, info_game_t *info, char *args);
void take_object_command(client_t *client, info_game_t *info, char *args);
void set_object_command(client_t *client, info_game_t *info, char *args);
void inventory_command(client_t *client, info_game_t *info, char *args);
void fork_command(client_t *client, info_game_t *info, char *args);

/*IA commands*/
static const ia_command_t ia_commands[] = {
    {"Forward", &forward_command, 7},
    {"Right", &right_command, 7},
    {"Left", &left_command, 7},
    {"Look", &look_command, 7},
    {"Connect_nbr", &connect_nbr_commad, 0},
    {"Incantation", &incantation_command, 300},
    {"Take", &take_object_command, 7},
    {"Set", &set_object_command, 7},
    {"Inventory", &inventory_command, 1},
    {"Fork", &fork_command, 42},
    {NULL, NULL, 0}
};

/*Utils*/
void display_line_ressource(int y, int *tab, client_t *client,
info_game_t *info);
void display_column_ressource(int x, int *tab, client_t *client,
info_game_t *info);
void print_ressource(int x, int y, map_t **map, client_t *client);
void init_eggs(egg_t *eggs, int x, int y, int available);
void set_id_eggs(egg_t *eggs, info_game_t *info);

#endif /* !COMMAND_H_ */
