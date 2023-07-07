/*
** EPITECH PROJECT, 2023
** panoramix
** File description:
** druid
*/

#include "panoramix.h"

void druid_lauch(void)
{
    printf("Druid: I'm ready... but sleepy...\n");
}

void druid_sleep(void)
{
    printf("Druid: I'm out of viscum. I'm going back to... zZz\n");
}

void refill(pthread_mutex_t *druid_mutex)
{
    extern panoramix_t *panoramix;
    pthread_mutex_lock(druid_mutex);
    panoramix->potion_count = panoramix->pot_size;
    panoramix->nb_refills--;
    panoramix->waker = false;
    pthread_mutex_unlock(druid_mutex);
    printf("Druid: Ah! Yes, yes, I'm awake! Working on it! Beware I can only");
    printf(" make %d more refills after this one.\n", panoramix->nb_refills);
    sem_post(&panoramix->semapore);
}

void *druid(void *arg __attribute__((unused)))
{
    extern panoramix_t *panoramix;
    pthread_mutex_t druid_mutex;
    pthread_mutex_init(&druid_mutex, NULL);

    druid_lauch();

    while (panoramix->nb_refills > 0) {
        if (panoramix->waker == true)
            refill(&druid_mutex);
    }
    if (panoramix->nb_refills != -100)
        druid_sleep();

    pthread_mutex_destroy(&druid_mutex);
    pthread_exit(NULL);
    return NULL;
}
