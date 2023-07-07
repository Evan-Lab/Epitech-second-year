/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-clement.martin
** File description:
** server
*/

#ifndef SERVER_H_
    #define SERVER_H_

    #include <stdio.h>
    #include <errno.h>
    #include <unistd.h>
    #include <string.h>
    #include <stdlib.h>
    #include <arpa/inet.h>
    #include <netinet/in.h>
    #include <sys/socket.h>
    #include <sys/ioctl.h>
    #include "structure.h"
    #include "command.h"

/*Server*/
int setup_server(info_serv_t *serv);
void init_sd(info_serv_t *serv);
int print_info(info_serv_t *serv);
void add_client(list_client_t **list, client_t *client);
void get_command(char *command, client_t *data, info_serv_t *serv);
void get_command_ai(char *command, client_t *data);
void first_connection(client_t *client, char *command, info_serv_t *info);
client_t *get_client_by_id(int id, list_client_t **list);

/*Utils*/
char *clean_str(char *str, char remove);
char *my_itoa(int value);
char **str_to_word_array(char *str, char separator);
void free_array(char **array);
int len_array(char **array);
void increment_time(info_game_t *info);
int get_len_double_char(char **list);
int check_int(char *str);
int check_float(char *str);
int get_len_list_action(list_action_t *list);
teams_t *get_teams_by_name(list_teams_t **list, char *name);

/*Game*/
void create_map(info_game_t *info_game);
void init_player(client_t *client, info_game_t *game);
void init_player_ai(client_t *client, info_game_t *game);
void add_in_action_list(ia_action_t *action, list_action_t **list);
void remove_element_at(int index, list_action_t **list);
void init_ressources(info_game_t *info_game);
void ressources_distribution(info_game_t *info_game);
void print_ressources_quantity(info_game_t *info_game);
void print_ressources_each_case(info_game_t *info_game);
void alloc_ressources_for_map_two(info_game_t *info_game, int i, int j);
void alloc_ressources_for_map(info_game_t *info_game);
int available_place_teams(list_client_t **list, char *teams);
int get_socket_gui(list_client_t **list);
void start_incantation(info_game_t *info, client_t *client);
void create_game_clock(info_game_t *info_game);
void spawn_ressources_on_game(info_serv_t *serv);
void start_fork(client_t *client, info_game_t *info);
void add_eggs(list_egg_t **list, egg_t *egg);
void init_things(info_serv_t *serv);
void player_death(client_t *client, info_serv_t *serv);
void create_clock_for_player(client_t *client);
int take_arg(char *args);

#endif /* !SERVER_H_ */
