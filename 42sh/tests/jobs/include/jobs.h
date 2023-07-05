/*
** EPITECH PROJECT, 2021
** B-PSU-210-MPL-2-1-42sh-kilyan.cotten
** File description:
** jobs.h
*/

#ifndef JOBS_H
    #define JOBS_H

    #include "mysh.h"

enum type {
    BEFORE,
    AFTER,
};

typedef struct list_s {
    char *state;
    int process_id;
    struct list_s *next;
} list_t;

typedef struct job_s {
    list_t *list;
} job_t;

void add_job(job_t *jobs, int id_process);
void my_exec(minishell_t *shell, char *path, char *parsed, job_t *jobs);
void get_path(minishell_t *shell, char *command, job_t *jobs);
char *strcat_alloc(char *dest, char *src);
void delete_char(char **str, char delete);
char *istrdup(char *src);

#endif /* JOBS_H */