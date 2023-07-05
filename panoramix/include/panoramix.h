/*
** EPITECH PROJECT, 2023
** panoramix [WSL : Ubuntu]
** File description:
** panoramix
*/

#include <pthread.h>
#include <semaphore.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef PANORAMIX_H_
    #define PANORAMIX_H_
    #define VALUE_ERROR  1
    #define THREAD_ERROR 2
    #define JOIN_ERROR   3
    #define USAGE        4
    #define MAL_ERROR    5
    #define ARG_ERROR    6

    #define VILL_START   10
    #define VILL_TRY     11
    #define VILL_CALL    12
    #define VILL_FIGHT   13
    #define VILL_SLEEP   14
    #define DRUID_START  15
    #define DRUID_REFILL 16
    #define DRUID_SLEEP  17

    typedef struct pano_s pano_t;
    extern pano_t pa;
    extern pthread_mutex_t mutex_p;
    extern sem_t druid_sem;
    extern sem_t villagers_sem;

    struct pano_s {
        int vi_nb;
        int left;
        int pot_st;
        int fight_nb;
        int refills_nb;
        int pot_cu;
        int *fights;
    };

    void *villager(void *param);
    void *druid(void *param);

#endif
