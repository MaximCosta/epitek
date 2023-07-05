/*
** EPITECH PROJECT, 2023
** panoramix [WSL : Ubuntu]
** File description:
** people
*/

#include "panoramix.h"

void print_action(int action, int idx)
{
    if (action == VILL_START)
        printf("Villager %d: Going into battle!\n", idx);
    if (action == VILL_TRY)
        printf("Villager %d: I need a drink... I see %d servings left.\n", idx,
            pa.pot_cu);
    if (action == VILL_CALL)
        printf("Villager %d: Hey Pano wake up! We need more potion.\n", idx);
    if (action == VILL_FIGHT)
        printf("Villager %d: Take that roman scum! Only %d left.\n", idx,
            pa.fights[idx]);
    if (action == VILL_SLEEP)
        printf("Villager %d: I'm going to sleep now.\n", idx);
    if (action == DRUID_START)
        printf("Druid: I'm ready... but sleepy...\n");
    if (action == DRUID_REFILL) {
        printf("Druid: Ah! Yes, yes. I'm awake! Working on it! Beware I can ");
        printf("only make %d more refills after this one.\n", pa.refills_nb);
    }
    if (action == DRUID_SLEEP)
        printf("Druid: I'm out of viscum. I'm going back to... zZz\n");
}

void *druid(__attribute__((unused)) void *param)
{
    print_action(DRUID_START, 0);
    for (;;) {
        sem_wait(&druid_sem);
        if (!pa.refills_nb)
            break;
        if (pa.pot_cu)
            continue;
        pa.refills_nb--;
        pa.pot_cu = pa.pot_st;
        sem_post(&villagers_sem);
        if (!pa.refills_nb)
            break;
    }
    print_action(DRUID_SLEEP, 0);
    return 0;
}

bool drink_potion(int idx)
{
    if (0 >= pa.pot_cu)
        return true;
    pa.pot_cu--;
    pthread_mutex_unlock(&mutex_p);
    pa.fights[idx] -= 1;
    print_action(VILL_FIGHT, idx);
    return false;
}

bool villager_action(int idx)
{
    pthread_mutex_lock(&mutex_p);
    print_action(VILL_TRY, idx);
    if (!drink_potion(idx))
        return false;
    if (0 < pa.refills_nb) {
        print_action(VILL_CALL, idx);
        sem_post(&druid_sem);
        sem_wait(&villagers_sem);
        if (!drink_potion(idx))
            return false;
    }
    pthread_mutex_unlock(&mutex_p);
    return true;
}

void *villager(void *param)
{
    int idx = (long) param;

    print_action(VILL_START, idx);
    while (pa.fights[idx]) {
        pthread_mutex_lock(&mutex_p);
        print_action(VILL_TRY, idx);
        if (!drink_potion(idx))
            continue;
        if (0 < pa.refills_nb) {
            print_action(VILL_CALL, idx);
            sem_post(&druid_sem);
            sem_wait(&villagers_sem);
            if (!drink_potion(idx))
                continue;
        }
        pthread_mutex_unlock(&mutex_p);
        break;
    }
    print_action(VILL_SLEEP, idx);
    return 0;
}
