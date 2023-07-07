/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-clement.martin
** File description:
** teams
*/

#include <stdlib.h>
#include <string.h>
#include "structure.h"

teams_t *get_teams_by_name(list_teams_t **list, char *name)
{
    list_teams_t *head = *list;

    while (head != NULL) {
        if (strcmp(head->teams->name, name) == 0)
            return head->teams;
        head = head->next;
    }
    return NULL;
}

void add_teams(list_teams_t **list, char *name, int nb)
{
    list_teams_t *node = malloc(sizeof(list_teams_t));
    list_teams_t *head = *list;
    teams_t *team = malloc(sizeof(teams_t));

    if (team == NULL)
        return;
    team->name = strdup(name);
    team->nb_connection = nb;
    team->list_egg = NULL;
    node->teams = team;
    node->next = NULL;
    if (*list == NULL) {
        *list = node;
        return;
    }
    while (head->next != NULL)
        head = head->next;
    head->next = node;
}
