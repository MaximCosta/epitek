/*
** EPITECH PROJECT, 2021
** B-CPE-200-MPL-2-1-lemin-flavio.moreno
** File description:
** parsing.h
*/

#ifndef PARSING_H
    #define PARSING_H

typedef struct parsing_s parsing_t;
typedef struct parsing_rooms_s parsing_rooms_t;
typedef struct parsing_links_s parsing_links_t;

struct parsing_s {
    int nb_ants;
    parsing_rooms_t *rooms;
    parsing_links_t *links;
    parsing_rooms_t *start;
    parsing_rooms_t *end;
};

struct parsing_rooms_s {
    char *name;
    int x;
    int y;
    parsing_rooms_t *next;
    char *data;
};

struct parsing_links_s {
    char *room_1;
    char *room_2;
    parsing_links_t *next;
    char *data;
};

parsing_t *do_parsing(void);

parsing_t *parsing_create(void);
parsing_t *parsing_destroy(parsing_t *parsing);

int parsing_rooms_append(parsing_t *parsing, char *content,
                        int is_start, int is_end);
void parsing_rooms_destroy(parsing_rooms_t *rooms);
parsing_rooms_t *parsing_rooms_create(char *content);

int parsing_links_append(parsing_t *parsing, char *content);
void parsing_links_destroy(parsing_links_t *links);
parsing_links_t *parsing_links_create(char *content);

//! STR
int str_len_without_comment(char *str);
void put_str_c(char *str);
int is_comment_after(char *str);

int count_char(char *s, char c);
void my_putstr_parsing(char *str);

int test_is_all_number_between(char *s, char c, int n);

int my_strlen(char *str);

char *my_strdup_p(char *s);

int add_connections(parsing_t *parsing, char *content);

parsing_t *do_parsing_verify(parsing_t *parsing);

#endif // PARSING_H
