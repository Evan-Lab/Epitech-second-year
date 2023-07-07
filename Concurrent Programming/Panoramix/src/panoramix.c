/*
** EPITECH PROJECT, 2023
** panoramix
** File description:
** algorithm
*/

#include "panoramix.h"

int algorithm(void)
{
    extern panoramix_t *panoramix;
    sem_init(&panoramix->semapore, PTHREAD_PROCESS_SHARED, 0);
    pthread_t villager_thread[panoramix->nb_villagers + 1];
    pthread_t druid_thread;
    pthread_create(&druid_thread, NULL, druid, NULL);

    panoramix->waker = false;
    panoramix->potion_count = panoramix->pot_size;

    for (int i = 0; i < panoramix->nb_villagers; i++) {
        pthread_create(&villager_thread[i], NULL, villageois,
            (void *)(intptr_t)i);
    }
    for (int i = 0; i < panoramix->nb_villagers; i++)
        pthread_join(villager_thread[i], NULL);

    panoramix->nb_refills = -100;
    pthread_join(druid_thread, NULL);
    sem_destroy(&panoramix->semapore);
    return 0;
}
