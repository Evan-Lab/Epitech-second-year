/*
** EPITECH PROJECT, 2023
** panoramix
** File description:
** villageois
*/

#include "panoramix.h"

void villageois_lauch(villageois_t *villageois)
{
    printf("Villager %d: Going into battle!\n", villageois->id);
}

void *villageois(void *arg)
{
    extern panoramix_t *panoramix;
    int id = (intptr_t)arg;
    villageois_t *villageois = malloc(sizeof(villageois_t));
    pthread_mutex_init(&villageois->villageois_mutex, NULL);

    villageois->status = 0;
    villageois->id = id;
    villageois->nb_fight = panoramix->nb_fight;

    villageois_lauch(villageois);

    while (villageois->status != -1) {
        if (villageois->status == 0)
            villageois_drink(villageois);
        if (villageois->status == 1)
            villageois_fight(villageois);
        if (villageois->status == 2)
            villageois_call(villageois);
    }
    return NULL;
}
