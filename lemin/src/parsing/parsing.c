/*
** EPITECH PROJECT, 2021
** B-CPE-200-MPL-2-1-lemin-flavio.moreno
** File description:
** parsing.c
*/

#include "my.h"

int get_nbr_ants(parsing_t *parsing)
{
    char *str = NULL;
    size_t size = 0;
    int i = 0;

    while (getline(&str, &size, stdin) > 0) {
        if (is_comment_after(str))
            continue;
        for (i = 0; !is_comment_after(&str[i]) &&
                    (str[i] >= '0' && str[i] <= '9'); i++);
        if (i < str_len_without_comment(str))
            return 84;
        my_putstr_parsing("#number_of_ants\n");
        put_str_c(str);
        str[str_len_without_comment(str)] = '\0';
        parsing->nb_ants = my_atoi(str);
        free(str);
        return 0;
    }
    free(str);
    return 84;
}

int test_command(char *content, int *st)
{
    if (!is_comment_after(content))
        return 0;
    if (!(!my_strcmp(content, "##start\n") ||
            !my_strcmp(content, "##end\n")) || *st)
        return *st ? 2 : 1;
    *st = !my_strcmp(content, "##start\n") ? 1 : 2;
    write(1, content, my_strlen(content));
    return 1;
}

int add_rooms(parsing_t *parsing, char *content, int *r, int *st)
{
    int res = test_command(content, st);
    int i = 0;

    if (res)
        return res - 1;
    if (count_char(content, '-')) {
        *r = 0;
        if (!parsing->start || !parsing->end)
            return 84;
        my_putstr_parsing("#tunnels\n");
        return 0;
    }
    if (count_char(content, ' ') != 2)
        return 84;
    for (i = 0; content[i] != ' '; i++);
    if (test_is_all_number_between(&content[i + 1], ' ', 2))
        return 84;
    put_str_c(content);
    parsing_rooms_append(parsing, content, *st == 1, *st == 2);
    *st = 0;
    return 0;
}

int add_connections(parsing_t *parsing, char *content)
{
    if (is_comment_after(content))
        return 0;
    if (count_char(content, '-') != 1 || count_char(content, ' '))
        return 84;
    put_str_c(content);
    parsing_links_append(parsing, content);
    return 0;
}

parsing_t *do_parsing(void)
{
    parsing_t *parsing = parsing_create();
    char *str = NULL;
    size_t size = 0;
    int rooms = 1;
    int start_end = 0;

    if (!parsing)
        return (NULL);
    if (get_nbr_ants(parsing) == 84)
        return parsing_destroy(parsing);
    my_putstr_parsing("#rooms\n");
    while (getline(&str, &size, stdin) != -1) {
        if (rooms && add_rooms(parsing, str, &rooms, &start_end))
            return parsing_destroy(parsing);
        if (!rooms && add_connections(parsing, str))
            return parsing_destroy(parsing);
    }
    free(str);
    my_putstr_parsing("#moves\n");
    return do_parsing_verify(parsing);
}
