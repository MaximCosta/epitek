/*
** EPITECH PROJECT, 2021
** src
** File description:
** main.c
*/

#include "../include/jobs.h"
#include "mysh.h"
#include <stdbool.h>

int charnfind(char *str, char find)
{
    int result = 0;

    for (int i = 0; str[i]; i++)
        if (str[i] == find)
            result++;
    return result;
}

void job_loop(minishell_t *shell, command_t *cmd_cpy, job_t *jobs)
{
    command_exec_t *exec_cpy = NULL;

    for (exec_cpy = cmd_cpy->exec; exec_cpy; exec_cpy = exec_cpy->next)
        if ((charnfind(exec_cpy->command, '&') % 2) == 1)
            delete_char(&exec_cpy->command, '&');
}

job_t *init_jobs(job_t *jobs)
{
    static bool init = false;

    if (init)
        return jobs;
    jobs = malloc(sizeof(job_t));
    jobs->list = NULL;
    init = true;
}

void jobs(minishell_t *shell, int type)
{
    job_t *jobs = init_jobs(jobs);
    command_t *cmd_cpy = shell->commands;

    if (type == BEFORE)
        for (; cmd_cpy; cmd_cpy = cmd_cpy->next)
            job_loop(shell, cmd_cpy, jobs);
    if (type == AFTER) {
        kill(shell->process_id, SIGSTOP);
        add_job(jobs, shell->process_id);
    }
}
