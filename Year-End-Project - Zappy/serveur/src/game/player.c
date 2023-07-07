/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** player
*/

#include "server.h"

void init_ressource_ai(client_t *client)
{
    client->inventory[0].name = strdup("food");
    client->inventory[0].quantity = 10;
    client->inventory[1].name = strdup("linemate");
    client->inventory[1].quantity = 2;
    client->inventory[2].name = strdup("deraumere");
    client->inventory[2].quantity = 0;
    client->inventory[3].name = strdup("sibur");
    client->inventory[3].quantity = 0;
    client->inventory[4].name = strdup("mendiane");
    client->inventory[4].quantity = 0;
    client->inventory[5].name = strdup("phiras");
    client->inventory[5].quantity = 0;
    client->inventory[6].name = strdup("thystame");
    client->inventory[6].quantity = 0;
}

char *init_player_orientation(void)
{
    char *orientation[4] = {"1", "2", "3", "4"};
    char *final_orientation = malloc(sizeof(char) * 2);
    int random = rand() % 4;

    final_orientation = orientation[random];
    return final_orientation;
}

void init_player(client_t *client, info_game_t *game)
{
    int map_width = game->map_width;
    int map_height = game->map_height;
    int gui_socket = get_socket_gui(&game->list_client);

    client->orientation_player = init_player_orientation();
    client->x = rand() % map_width;
    client->y = rand() % map_height;
    client->timer = malloc(sizeof(clock_struct_t));
    if (client->timer == NULL)
        return;
    client->number_client = client->socket;
    client->incantation_level = 1;
    client->incantaion_in_progress = 0;
    dprintf(gui_socket, "pnw %d %d %d %s %d %s\n",
    client->number_client, client->x,
    client->y, client->orientation_player,
    client->incantation_level, client->team_name);
    client->action = NULL;
}

void egg_available(client_t *client, teams_t *teams, list_client_t **list)
{
    list_egg_t *head = teams->list_egg;
    int gui_socket = get_socket_gui(list);
    int check = 0;
    int random_nbr = 0;

    if (gui_socket == -1)
        return;
    srand(time(0));
    while (head != NULL && check == 0) {
        random_nbr = 1 + rand() % 10;
        if (head->egg->available == 1 && random_nbr > 5) {
            client->x = head->egg->x;
            client->y = head->egg->y;
            dprintf(gui_socket, "ebo %d\n", head->egg->id);
            return;
        }
        if ((head = head->next) == NULL)
            head = teams->list_egg;
    }
}

void init_player_ai(client_t *client, info_game_t *game)
{
    int nb_client_in_team = available_place_teams(&game->list_client,
    client->team_name);
    int available_place = game->client_max - nb_client_in_team;

    dprintf(client->socket, "%d\n", available_place);
    dprintf(client->socket, "%d %d\n", game->map_width, game->map_height);
    init_player(client, game);
    create_clock_for_player(client);
    init_ressource_ai(client);
    egg_available(client, get_teams_by_name(&game->teams_name,
    client->team_name),
    &game->list_client);
}
