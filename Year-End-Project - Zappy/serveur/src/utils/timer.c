/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** timer
*/

#include <stdio.h>
#include "structure.h"

void increment_time(info_game_t *info)
{
    time_t currentTime = time(NULL);
    info->timer->seconds = difftime(currentTime, info->timer->startTime);
}
