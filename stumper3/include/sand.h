/*
** EPITECH PROJECT, 2022
** include/sand
** File description:
** r/ProgrammerHumor
*/

#ifndef SAND_H_
    #define SAND_H_
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <string.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>

typedef struct sand_s{
    int sx;
    int sy;
    int cx;
    int cy;
    int loop;
    char *base;
    int **maps;
} sand_t;

void free_all(sand_t *sand, char *map);
int print_map(sand_t *sand);
char *load_file_in_mem(char *fp, char *str);
int is_number(char *str);
int my_exit(char *str, int code);
int count_char(char *str, char c);
int check_map_char(char ch, char *str);
void check_map(char *str, char *buffer);
void compare_counts(int count1, int count2);
void check_lines_len(char *buffer);
int **buff_to_int(char *buffer, char *str, sand_t *sand);
int is_supof(sand_t *sand);
int is_unique(char *str);

#endif /* !SAND_H_ */
