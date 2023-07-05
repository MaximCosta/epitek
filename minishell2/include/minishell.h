/*
** EPITECH PROJECT, 2022
** minishell1 [WSL: Ubuntu]
** File description:
** minishell
*/

#ifndef MINISHELL_H_
    #define MINISHELL_H_
    #include "my.h"
    #include "my_printf.h"
    #include <limits.h>
    #include <string.h>
    #include <unistd.h>
    #define IS_ALNUM(x) ( \
        ( (x) >= 'a' && (x) <= 'z') || \
        ( (x) >= 'A' && (x) <= 'Z') || \
        ( (x) >= '0' && (x) <= '9' ))
typedef struct env_s {
    char **paths;
    char **cmd;
    char **env;
    char *puser;
    char *user;
    char *host;
    int lenh;
    int lenp;
} env_t;
int count_chars(char *c, char *str);
char **str_split(char *c, char *str, int code);
int lst(char *str);
char *str_catcat(char *str1, char *str2, char *str3);
void fork_process(env_t *);
char *get_execute(env_t *);
char *concat(char *s1, char *s2);
char **my_strdump2d(char **str, int i);
void env_shw(char *env[]);
char *env_get(char *env[], char *s1);
int env_set(env_t *fenv, char *s1, char *s2);
int env_set1(env_t *fenv, char *s1, char *s2, int i);
int env_set2(env_t *fenv, char *s1, char *s2, int i);
int env_del(char *env[], char *s1);
int my_env(env_t *fenv);
int my_setnev(env_t *fenv);
int my_unsetenv(env_t *fenv);
int my_cd(env_t *fenv);
int my_cd_exec(env_t *fenv, char buf[PATH_MAX]);
int my_isalnum(char *s1, int size);
char *concat(char *s1, char *s2);
char **my_strdump2d(char **str, int i);
int exit_code(char **strs);
void fork_wait(env_t *, int *, char *);
int other_command(env_t *fenv);
void bash_print(env_t *fenv);
#endif /* !MINISHELL_H_ */
