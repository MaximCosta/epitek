/*
** EPITECH PROJECT, 2021
** B-CPE-200-MPL-2-1-lemin-flavio.moreno [WSL: Ubuntu-20.04]
** File description:
** parsing_struct_create.c
*/

#include "my.h"

int get_char_pos(char *s, char c)
{
    int i = 0;

    for (; s[i] && s[i] != '\n' && !is_comment_after(&s[i]); i++)
        if (s[i] == c)
            return i;
    return -1;
}

parsing_rooms_t *parsing_rooms_create(char *content)
{
    parsing_rooms_t *new_room = malloc(sizeof(parsing_rooms_t));
    content = my_strdup_p(content);
    int tmp = get_char_pos(content, ' ');
    char *tmp_str = &content[tmp + 1];

    if (!new_room)
        return NULL;
    new_room->data = content;
    content[get_char_pos(content, ' ')] = '\0';
    new_room->name = content;
    tmp = get_char_pos(tmp_str, ' ');
    tmp_str[tmp] = '\0';
    new_room->x = my_atoi(tmp_str);
    tmp_str = &tmp_str[tmp + 1];
    tmp_str[str_len_without_comment(tmp_str)] = '\0';
    new_room->y = my_atoi(tmp_str);
    new_room->next = NULL;
    return new_room;
}

parsing_links_t *parsing_links_create(char *content)
{
    parsing_links_t *new_link = malloc(sizeof(parsing_links_t));
    content = my_strdup_p(content);
    int tmp = get_char_pos(content, '-');

    if (!new_link)
        return NULL;
    new_link->data = content;
    content[tmp] = '\0';
    new_link->room_1 = content;
    content = &content[tmp + 1];
    content[str_len_without_comment(content)] = '\0';
    new_link->room_2 = content;
    new_link->next = NULL;
    return new_link;
}
