/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/
#include "../../include/asm.h"

static void store_label(parsing_t *parsing, char *line, char *label)
{
    label_t *labelt = malloc(sizeof(label_t));

    label[my_strlen(label) - 1] = 0;
    if (already_exist_label(parsing->labels, label))
        exit(84);
    labelt->name = my_strdup(label);
    labelt->offset = 0;
    list_insert_first(&parsing->labels, labelt);
}

void store_labels(parsing_t *parsing, FILE *file)
{
    size_t line_buf_size = 0;
    char *line_buf = NULL;
    char *formatted_line_buf = NULL;
    char **splitted = 0;

    while (getline(&line_buf, &line_buf_size, file) >= 0) {
        if (!line_buf)
            continue;
        formatted_line_buf = lstrip(rstrip(remove_after_char(line_buf, '#')));
        if (!formatted_line_buf)
            continue;
        splitted = split(formatted_line_buf, " ,\t");
        if (is_label_declaration(splitted[0]))
            store_label(parsing, line_buf, splitted[0]);
    }
}

void check_file_content(parsing_t *parsing, FILE *file)
{
    size_t line_buf_size = 0;
    char *line_buf = NULL;
    char *formatted_line_buf = NULL;

    while (getline(&line_buf, &line_buf_size, file) >= 0) {
        if (!line_buf)
            continue;
        formatted_line_buf = lstrip(rstrip(remove_after_char(line_buf, '#')));
        if (!formatted_line_buf)
            continue;
        if (formatted_line_buf[0] == '.')
            handle_header_line(formatted_line_buf, parsing);
        else
            first_handle_instruction_line(formatted_line_buf, parsing);
    }
}
