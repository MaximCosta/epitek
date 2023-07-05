/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/
#include "../../../include/asm.h"

void handle_header_line(char *line, parsing_t *parsing)
{
    char **splitted = split(line, " \t");

    if (my_strcmp(splitted[0], NAME_CMD_STRING) == 0) {
        if (parsing->has_comment || parsing->has_name)
            exit(84);
        parsing->has_name = true;
        handle_header_name_line(line, splitted, parsing);
        return;
    }
    if (my_strcmp(splitted[0], COMMENT_CMD_STRING) == 0) {
        if (parsing->has_comment || !parsing->has_name)
            exit(84);
        if (parsing->prog_size != 0)
            exit(84);
        parsing->has_comment = true;
        handle_header_comment_line(line, splitted, parsing);
        return;
    }
    exit(84);
}

void handle_header_name_line(char *line, char **splitted, parsing_t *parsing)
{
    if (!splitted[1])
        exit(84);
    for (int i = 5; line[i]; i++) {
        if (!parsing->quotted && line[i] == '"') {
            parsing->quotted = true;
            continue;
        }
        if (parsing->quotted && line[i] == '"') {
            exit_if_condition(line[i + 1], 84);
            parsing->quotted = false;
            continue;
        }
        if (my_strlen(parsing->name) >= PROG_NAME_LENGTH)
            exit(84);
        if (parsing->quotted)
            parsing->name[my_strlen(parsing->name)] = line[i];
    }
    if (parsing->quotted)
        exit(84);
}

void handle_header_comment_line(
    char *line, char **splitted, parsing_t *parsing)
{
    if (!splitted[1])
        exit(84);
    for (int i = 5; line[i]; i++) {
        if (!parsing->quotted && line[i] == '"') {
            parsing->quotted = true;
            continue;
        }
        if (parsing->quotted && line[i] == '"') {
            exit_if_condition(line[i + 1], 84);
            parsing->quotted = false;
            continue;
        }
        if (my_strlen(parsing->comment) + 1 > COMMENT_LENGTH)
            exit(84);
        if (parsing->quotted)
            parsing->comment[my_strlen(parsing->comment)] = line[i];
    }
    if (parsing->quotted)
        exit(84);
}
