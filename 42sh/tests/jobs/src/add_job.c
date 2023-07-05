/*
** EPITECH PROJECT, 2021
** tests
** File description:
** add_job.c
*/

#include "../include/jobs.h"
#include "mysh.h"

void add_job(job_t *jobs, int id_process)
{
    list_t *copy = jobs->list;
    list_t *new = NULL;
    int i = 1;

    if (!jobs->list) {
        jobs->list = malloc(sizeof(list_t));
        jobs->list->process_id = id_process;
        jobs->list->state = "+ Running";
        jobs->list->next = NULL;
    } else {
        for (; copy->next; copy = copy->next, i++);
        new = malloc(sizeof(list_t));
        new->process_id = id_process;
        new->state = "+ Running";
        new->next = NULL;
        copy->next = new;
    }
    printf("[%d] %d\n", i, id_process);
}
