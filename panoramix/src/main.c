/*
** EPITECH PROJECT, 2023
** panoramix [WSL : Ubuntu]
** File description:
** main
*/

#include "panoramix.h"

pano_t pa;
pthread_mutex_t mutex_p;
sem_t druid_sem;
sem_t villagers_sem;

int error_handling(int return_value, int code)
{
    if (return_value == VALUE_ERROR)
        fprintf(stderr, "Values must be >0.\n");
    if (return_value == THREAD_ERROR)
        fprintf(stderr, "Error: failed to create thread\n");
    if (return_value == JOIN_ERROR)
        fprintf(stderr, "Error: failed to join thread\n");
    if (return_value == USAGE) {
        fprintf(stderr, "USAGE: ./panoramix ");
        fprintf(stderr, "<nb_villagers> <pot_size> <nb_fights> <nb_refills>\n");
    }
    if (return_value == MAL_ERROR)
        fprintf(stderr, "Error: malloc failed\n");
    if (return_value == ARG_ERROR)
        fprintf(stderr, "Error: wrong number of arguments\n");
    return code;
}

int get_arguments(int ac, char **av)
{
    if (ac != 5)
        return ARG_ERROR;
    pa.vi_nb = atoi(av[1]);
    pa.pot_st = atoi(av[2]);
    pa.fight_nb = atoi(av[3]);
    pa.refills_nb = atoi(av[4]);
    if (pa.vi_nb <= 0 || pa.pot_st <= 0 || pa.fight_nb <= 0
        || pa.refills_nb <= 0)
        return VALUE_ERROR;
    if ((pa.fights = malloc(sizeof(int) * pa.vi_nb)) == NULL)
        return MAL_ERROR;
    for (int i = 0; i < pa.vi_nb; i++)
        pa.fights[i] = pa.fight_nb;
    pa.pot_cu = pa.pot_st;
    pa.left = pa.vi_nb;
    return 0;
}

int launch_threads(void)
{
    pthread_t *threads = malloc(sizeof(pthread_t) * (pa.vi_nb + 2));

    if (threads == NULL)
        return 84;
    pthread_create(&threads[pa.vi_nb], NULL, druid, NULL);
    for (long i = 0; i < pa.vi_nb; i++)
        if (pthread_create(&threads[i], NULL, villager, (void *) i))
            error_handling(THREAD_ERROR, false);
    for (int i = 0; i < pa.vi_nb; i++)
        if (pthread_join(threads[i], NULL))
            error_handling(JOIN_ERROR, false);
    pthread_cancel(threads[pa.vi_nb]);
    free(threads);
    return 0;
}

int main(int argc, char **argv)
{
    int return_value = 0;

    if ((return_value = get_arguments(argc, argv)))
        return error_handling(return_value, error_handling(USAGE, 84));
    sem_init(&druid_sem, 0, 0);
    sem_init(&villagers_sem, 0, 0);
    pthread_mutex_init(&mutex_p, NULL);
    return_value = launch_threads();
    pthread_mutex_destroy(&mutex_p);
    sem_destroy(&druid_sem);
    sem_destroy(&villagers_sem);
    free(pa.fights);
    return return_value;
}
