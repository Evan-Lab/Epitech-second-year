/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** args
*/

#ifndef ARGS_H_
    #define ARGS_H_

    #include <stdlib.h>
    #include <string.h>
    #include "structure.h"

/*Getters*/
int get_port(info_serv_t *info, char **av, int ac, int count);
int get_map_width(info_serv_t *info, char **av, int ac, int count);
int get_map_height(info_serv_t *info, char **av, int ac, int count);
int get_client_max(info_serv_t *info, char **av, int ac, int count);
double get_time_unit(info_serv_t *info, char **av, int ac, int count);
int get_args(info_serv_t *info_serv, int ac, char **av);

/*Checkers*/
int check_int(char *str);
int check_float(char *str);

void add_teams(list_teams_t **list, char *name, int nb);

#endif /* !ARGS_H_ */
