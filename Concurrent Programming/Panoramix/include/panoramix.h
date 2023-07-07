/*
** EPITECH PROJECT, 2023
** panoramix
** File description:
** panoramix
*/

#ifndef PANORAMIX_H
    #define PANORAMIX_H
    #include <stdio.h>
    #include <stdlib.h>
    #include <pthread.h>
    #include <stdbool.h>
    #include <semaphore.h>
    #include <unistd.h>
    #include <aio.h>

//Structure panoramix//

typedef struct panoramix_s {
    int nb_villagers; // nb of villagers, must be > 0
    int id; // id of the villager
    int pot_size; // nb of pot that can be contain each cook, must be > 0
    int nb_fight; // nb of fight that each villager will engage, must be > 0
    int nb_refills; // nb of refill the druid will do, must be > 0
    int potion_count; // nb of actual potion count
    sem_t semapore;
    bool waker; // status of the druid if it's awake or not
} panoramix_t;

// Structure villageois //

typedef struct villageois_s {
    int id; // id of the villager
    int status; // status of the villager
    int nb_fight; // nb of fight that each villager will engage, must be > 0
    pthread_mutex_t villageois_mutex; // mutex of the villager
} villageois_t;

// Algorithm of the project //

int algorithm(void);
void *villageois(void *arg);
void *druid(void *arg);
int check_args(int argc, char **argv);

//villageois actions //

void villageois_fight(villageois_t *villageois);
void villageois_drink(villageois_t *villageois);
void villageois_call(villageois_t *villageois);

#endif //PANORAMIX_H
