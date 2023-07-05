/*
** EPITECH PROJECT, 2022
** include/my
** File description:
** man man
*/

#ifndef MY_H_
    #define MY_H_
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>

typedef struct {
    char **grid;
    char **words;
    char **word;
    int size;
} data_t;

void grid_print(data_t *data, int in, int total);
void free_all(data_t *data); 
void fill_grid(data_t *data);
int insert(data_t *data, char *word, int x, int y);
int fill_ramdom(data_t *data);
data_t *init_data(void);
int get_next(data_t *data);
char *load_file(char *fp);
int check_digits(char *buffer);
int count_words_in_grid(char **words, char **grid);
int words_in_2darray(data_t *data, char *buffer);
#endif /* !MY_H_ */
