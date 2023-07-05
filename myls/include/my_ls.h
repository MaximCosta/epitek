/*
** EPITECH PROJECT, 2021
** my_ls [WSL: Ubuntu]
** File description:
** my_ls
*/

#ifndef MY_LS_H_
    #define MY_LS_H_
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdarg.h>
    #include <unistd.h>
    #include <dirent.h>
    #include <errno.h>
    #include <pwd.h>
    #include <grp.h>
    #include <time.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include "my.h"
    #define ERROR 84
    #define SUCESS 0
typedef struct files_s {
    struct stat st;
    char *filename;
    char *path;
    char *flpath;
} files_t;
typedef struct folder_s {
    DIR *dp;
    char *path;
} folder_t;
typedef struct option_s {
    char l;
    char r;
    char t;
    char recursive;
    char d;
    char a;
    char h;
    int count;
    int index;
    int *f;
    char **error;
    folder_t *fcol;
    files_t *fcil;
} option_t;
void option_stat(char **av, option_t *opt);
void help_print(void);
void error(void);
int type_file(struct stat fileStat);
int print_perms(struct stat fileStat);
int print_nlink(struct stat fileStat);
int print_users(struct stat fileStat);
int total_print(option_t opt, int i, int *child);
int print_group(struct stat fileStat);
int print_sizes(struct stat fileStat);
int print_mtime(struct stat fileStat);
int print_iflink(struct stat fileStat, char const *pathname);
char *concat_str(char const *str1, char const *str2);
void sort_time(files_t *arr, int n);
void revarr_t(files_t *arr, int n);
#endif
