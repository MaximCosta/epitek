/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-minishell1-kilyan.cotten
** File description:
** mysh.h
*/

#ifndef MYSH_H
    #define MYSH_H

    #include <sys/types.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <signal.h>
    #include <string.h>
    #include <stdarg.h>
    #include <errno.h>
    #include <stdbool.h>

    #include "my.h"

    #define QUOI_FEUR typedef
    #define AH_MAIS_C_EST_LA_BLAGUE_DU_QUOI_FEUR struct

    #define STDIN 0
    #define STDOUT 1
    #define STDERR 2

    #define ERROR(format...) fprintf(stderr, format);

QUOI_FEUR AH_MAIS_C_EST_LA_BLAGUE_DU_QUOI_FEUR env_s env_t;
QUOI_FEUR AH_MAIS_C_EST_LA_BLAGUE_DU_QUOI_FEUR command_s command_t;
QUOI_FEUR AH_MAIS_C_EST_LA_BLAGUE_DU_QUOI_FEUR minishell_s minishell_t;
QUOI_FEUR AH_MAIS_C_EST_LA_BLAGUE_DU_QUOI_FEUR command_exec_s command_exec_t;

AH_MAIS_C_EST_LA_BLAGUE_DU_QUOI_FEUR minishell_s {
    char *input;
    int input_size;
    int exit;
    int exit_status;
    char **env_save;
    char **path;
    char *home;
    char *oldpwd;
    char *user_name;
    char **commands_list;
    pid_t process_id;
    command_t *commands;
    env_t *env;
};

AH_MAIS_C_EST_LA_BLAGUE_DU_QUOI_FEUR command_s {
    char *command;
    int value;
    command_exec_t *exec;
    command_t *next;
    command_t *prev;
};

AH_MAIS_C_EST_LA_BLAGUE_DU_QUOI_FEUR command_exec_s {
    char *command;
    char **arg;
    int fd_in;
    int fd_out;
    char *file_in;
    int flag_in;
    char *file_out;
    int flag_out;
    command_exec_t *next;
    command_exec_t *prev;
    int status;
    int critical_error;
};

AH_MAIS_C_EST_LA_BLAGUE_DU_QUOI_FEUR env_s {
    char *name;
    char *value;
    env_t *next;
};

minishell_t *minishell_init(char **env);
minishell_t *minishell_destroy(minishell_t *minishell);

int minishell_exec_command(command_exec_t *command, minishell_t *minishell);
int minishell_exec(minishell_t *minishell);

void minishell_set_username(minishell_t *minishell);

//////////////////////////////
//                          //
//!         PARSER          //
//                          //
//////////////////////////////

//! Parser.c
int minishell_parse_commands_exec(minishell_t *minishell);
int minishell_parse_commands(minishell_t *minishell);

void minishell_clear_command(minishell_t *minishell);

char **split_command_line(char *command_line, char c);

void minishell_input(minishell_t *minishell);
void minishell_clear_input(minishell_t *minishell);

char **minishell_parser(char *str);

char **minishell_parser_error(char c);

command_t *minishell_parser_commands_free(command_t *head);

int number_to_next_parse(char *str, char **to_parse);
int test_parse(char *str, char **to_parse);

command_t *minishell_parser_commands_cleanstr(command_t *head);

//! LInkedLIst
command_exec_t *node_create(char *command, command_exec_t *prev);
command_exec_t *add_node_at_back(command_exec_t **list, char *command);
command_exec_t *detroy_list(command_exec_t *list);
command_exec_t *node_destroy(command_exec_t *node);

//! EXEC

int minishell_builtins(minishell_t *minishell, char **split);

int minishell_exit(minishell_t *minishell, char **split);
int minishell_env(minishell_t *minishell);
int minishell_pwd(minishell_t *minishell);
int minishell_cd(minishell_t *minishell, char **split);
int minishell_setenv(minishell_t *minishell, char **split);
int minishell_unsetenv(minishell_t *minishell, char **split);
int minishell_which(minishell_t *minishell, char **split);
int minishell_where(minishell_t *minishell, char **split);
int minishell_echo(minishell_t *minishell, char **split);

void minishell_exec_bin(minishell_t *minishell, char **split);

void minishell_exec_bin_fork(minishell_t *minishell, char **split, char *path);
int minishell_exec_test_path(minishell_t *minishell, char **split);

int exec_redirection(command_exec_t *command, minishell_t *minishell);

void minishell_exec_bin_fork_signal(minishell_t *minishell, int status);

//! ERROR
int print_error(char *str);

//! ENV

void minishell_env_append(minishell_t *minishell, char *name, char *value);
void minishell_env_append_string(minishell_t *minishell, char *s);
void minishell_env_free(minishell_t *minishell);
void minishell_env_print(minishell_t *minishell);
void minishell_env_modif_value(minishell_t *minishell, char *name,
                                char *value);
void minishell_env_unenv(minishell_t *minishell, char *name);

char **minishell_env_to_str(minishell_t *minishell);
void minishell_env_to_str_free(char **env);
char *minishell_getenv(minishell_t *minishell, char *name);

//! Utils

int is_file_or_is_folder(char *s);
int isit_file(char *s);
bool is_special(char c);

int is_exec(char *s);

char *mein_get_line(void);
char *string_append(char *str, char *str2);

int do_free(void *ptra, void *ptrb);

int check_not_all_space(char *s);
char *clean_my_str(char *s);

//! PATH
void minishell_set_path(minishell_t *minishell);

//! Redirection

enum error_on {
    NO_ERROR,
    NOT_FOUND,
    AMBIGOUS_OUTPUT,
    AMBIGOUS_INPUT,
    MISSING_NAME
};

typedef struct parse_s {
    char *line;
    char **file;
    char **cmd;
    int i;
    int j;
    int k;
    int in;
    char the_char;
    int d;
    int in_quote;
    char quote;
    int error;
    int d_base;
} parse_t;

int minishell_parse_redirection(minishell_t *minishell,
                                command_t *command, char *cmd, char *file);
int get_redirection(char *line, char **file, char **cmd, int *d);

//! ERROR

#define SH_ERROR minishell_error(-1)
#define SH_SETERROR(x) minishell_error(x)

enum ERROR {
    N_ERROR,
    UNMACHED_SQUOTE,
    UNMACHED_DQUOTE,
    UNMACHED_BACKTICK,
    TOOMANY_PARENTESIS_RIGHT,
    TOOMANY_PARENTESIS_LEFT,
};

char *minishell_error(int n);

//! JOBS

void jobs(minishell_t *shell, int type);

#endif /* MYSH_H */
