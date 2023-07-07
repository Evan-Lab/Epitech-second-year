/*
** EPITECH PROJECT, 2023
** panoramix
** File description:
** villageois_actions
*/

#include "panoramix.h"

void villageois_call(villageois_t *villageois)
{
    extern panoramix_t *panoramix;
    printf("Villager %d: Hey Pano wake up! We need more potion.\n",
        villageois->id);

    pthread_mutex_lock(&villageois->villageois_mutex);
    panoramix->waker = true;
    pthread_mutex_unlock(&villageois->villageois_mutex);
    sem_wait(&panoramix->semapore);

    villageois->status = 0;
}

void villageois_fight(villageois_t *villageois)
{
    extern panoramix_t *panoramix;
    if (villageois->nb_fight != 0) {
        villageois->nb_fight--;
        printf("Villager %d: Take that roman scum! Only %d left.\n",
            villageois->id, villageois->nb_fight);

        if (villageois->nb_fight == 0) {
            printf("Villager %d: I'm going to sleep now.\n", villageois->id);
            villageois->status = -1;
            return;
        }

        villageois->status = 0;
    }
    if (villageois->nb_fight == 0) {
        printf("Villager %d: I'm going to sleep now.\n", villageois->id);
        villageois->status = -1;
    }
}

void villageois_drink(villageois_t *villageois)
{
    extern panoramix_t *panoramix;
    if (panoramix->waker == true)
        sem_wait(&panoramix->semapore);

    printf("Villager %d: I need a drink... I see %d servings left.\n",
        villageois->id, panoramix->potion_count);
    pthread_mutex_lock(&villageois->villageois_mutex);
    panoramix->potion_count--;
    pthread_mutex_unlock(&villageois->villageois_mutex);

    villageois->status = 1;
    if (panoramix->potion_count == -1)
        villageois->status = 2;
}
