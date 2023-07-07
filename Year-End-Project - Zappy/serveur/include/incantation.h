/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-clement.martin
** File description:
** incantation
*/

#ifndef INCANTATION_H_
    #define INCANTATION_H_

    #include "server.h"

int choose_client(list_client_t **list, int min);
int get_len_list_client(list_client_t **list);
list_client_t *get_list_client_same_level(list_client_t **list, int level,
int id);
void send_end_incantation(info_game_t *game, client_t *client, char *res);
void start_incantation(info_game_t *info, client_t *client);
int define_nb_of_player(client_t *client);
int remove_ressource(client_t *client, map_t **map, char *name, int nb);
int check_ressource(client_t *client, map_t **map, char *name, int nb);

void incantation_level_2(client_t *client, info_game_t *info);
void incantation_level_3(client_t *client, info_game_t *info);
void incantation_level_4(client_t *client, info_game_t *info);
void incantation_level_5(client_t *client, info_game_t *info);
void incantation_level_6(client_t *client, info_game_t *info);
void incantation_level_7(client_t *client, info_game_t *info);
void incantation_level_8(client_t *client, info_game_t *info);

#endif /* !INCANTATION_H_ */
