/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/
#include "../../include/asm.h"

void compile_asm(char *filename, parsing_t *parsing)
{
    FILE *file = fopen(filename, "r");

    if (file == NULL)
        exit(84);
    store_labels(parsing, file);
    fseek(file, 0, SEEK_SET);
    check_file_content(parsing, file);
    fseek(file, 0, SEEK_SET);
    create_compiled_file(filename, parsing);
    compile_header(parsing);
    fseek(file, 0, SEEK_SET);
    compile_code(parsing, file);
    fclose(file);
}

void compile_header(parsing_t *parsing)
{
    int magic = COREWAR_EXEC_MAGIC;
    int i = 0;
    int big = little_to_big_endian(parsing->prog_size);

    write(parsing->file_fd, &magic, 4);
    write(parsing->file_fd, parsing->name, PROG_NAME_LENGTH);
    write(parsing->file_fd, &i, 4);
    write(parsing->file_fd, &big, 4);
    write(parsing->file_fd, parsing->comment, COMMENT_LENGTH);
    write(parsing->file_fd, &i, 4);
}

static int write_pcb(parsing_t *parsing, char *line, int mnemonique_index)
{
    char **splitted = split(line, " ,\t");
    int parameter_type = T_NONE;
    char *pcb = my_calloc(sizeof(char) * 9);
    int to_dec = 0;

    for (int i = 1; i <= op_tab[mnemonique_index].nbr_args; i++) {
        parameter_type = get_param_type(parsing, rstrip(lstrip(splitted[i])));
        if (parameter_type == T_REG)
            my_strcat(pcb, "01");
        if (parameter_type == T_DIR)
            my_strcat(pcb, "10");
        if (parameter_type == T_IND)
            my_strcat(pcb, "11");
    }
    while (my_strlen(pcb) < 8)
        my_strcat(pcb, "0");
    to_dec = bin_to_dec(pcb);
    write(parsing->file_fd, &to_dec, 1);
    return 1;
}

static void compile_line(parsing_t *parsing, char *line, int *curr_byte)
{
    char **splitted = split(line, " \t");
    char *first = splitted[0];
    int mnem_index = 0;
    int total_bytes = 0;

    if (is_label_declaration(first) && my_strlen(first) == my_strlen(line))
        return;
    if (is_label_declaration(first)) {
        line = line + my_strlen(split(first, ":")[0]) + 1;
        splitted = split(line, " \t");
        first = splitted[0];
    }
    mnem_index = get_mnemonique_index(first);
    write(parsing->file_fd, &op_tab[mnem_index].code, 1);
    total_bytes += 1;
    if (op_tab[mnem_index].has_pcb)
        total_bytes += write_pcb(parsing, line, mnem_index);
    total_bytes += write_params(parsing, line, mnem_index, curr_byte);
    *curr_byte += total_bytes;
}

void compile_code(parsing_t *parsing, FILE *file)
{
    size_t line_buf_size = 0;
    char *line_buf = NULL;
    char *formatted_line_buf = NULL;
    int current_byte_read = 0;

    while (getline(&line_buf, &line_buf_size, file) >= 0) {
        if (!line_buf)
            continue;
        formatted_line_buf = lstrip(rstrip(remove_after_char(line_buf, '#')));
        if (!formatted_line_buf)
            continue;
        if (formatted_line_buf[0] == '.')
            continue;
        compile_line(parsing, formatted_line_buf, &current_byte_read);
    }
}
