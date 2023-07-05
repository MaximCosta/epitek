/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/
#include "../../include/asm.h"

static void write_params_indirect(
    parsing_t *parsing, char **splitted, int *res, int *elem[3])
{
    int label_offset = 0;

    if (splitted[*elem[1]][0] == ':') {
        label_offset =
            get_label_offset(&parsing->labels, splitted[*elem[1]] + 1);
        *elem[0] = little_to_big_endian(label_offset - *elem[2]);
        *elem[0] = (*elem[0] << 16) | (*elem[0] >> 16);
        write(parsing->file_fd, &(*elem[0]), 2);
        *res += 2;
    } else {
        *elem[0] = little_to_big_endian(my_getnbr_long(splitted[*elem[1]]));
        *elem[0] = (*elem[0] << 16) | (*elem[0] >> 16);
        write(parsing->file_fd, &(*elem[0]), 2);
        *res += 2;
    }
}

static void write_params_direct(
    parsing_t *parsing, char **splitted, char *mnemonique, int *elem[4])
{
    int label_offset =
        get_label_offset(&parsing->labels, splitted[*elem[2]] + 2);
    int num = little_to_big_endian(label_offset - *elem[3]);

    if (is_index(rstrip(lstrip(mnemonique)), *elem[2])) {
        num = (num << 16) | (num >> 16);
        write(parsing->file_fd, &num, 2);
        *elem[0] += 2;
        return;
    }
    if (op_tab[*elem[1]].directsize == 32) {
        write(parsing->file_fd, &num, 4);
        *elem[0] += 4;
    } else {
        num = (num << 16) | (num >> 16);
        write(parsing->file_fd, &num, 2);
        *elem[0] += 2;
    }
}

int find_num(parsing_t *parsing, char **splitted, int i, int curr_byte)
{
    int num = 0;

    if (splitted[i][0] == '%' && splitted[i][1] == ':')
        num = little_to_big_endian(
            get_label_offset(&parsing->labels, splitted[i] + 2) - curr_byte);
    else
        num = little_to_big_endian(my_getnbr_long(splitted[i] + 1));
    return num;
}

static void write_params_dir(
    parsing_t *parsing, char **splitted, char *mnemonique, int *elem[5])
{
    int num = 0;
    int i = *elem[1];

    if (*elem[0] == T_DIR) {
        num = find_num(parsing, splitted, i, *elem[2]);
        if (is_index(rstrip(lstrip(mnemonique)), i)) {
            num = (num << 16) | (num >> 16);
            write(parsing->file_fd, &num, 2);
            *(elem[4]) += 2;
            return;
        }
        if (op_tab[*elem[3]].directsize == 32) {
            write(parsing->file_fd, &num, 4);
            *(elem[4]) += 4;
        } else {
            num = (num << 16) | (num >> 16);
            write(parsing->file_fd, &num, 2);
            *(elem[4]) += 2;
        }
    }
}

int write_params(
    parsing_t *parsing, char *line, int mnem_index, int *curr_byte)
{
    char *mnemonique = split(line, " \t")[0];
    char **splitted = split(line, " ,\t");
    int parameter_type = T_NONE;
    int num = 0;
    int res = 0;

    for (int i = 1; i <= op_tab[mnem_index].nbr_args; i++) {
        parameter_type = get_param_type(parsing, rstrip(lstrip(splitted[i])));
        if (parameter_type == T_REG) {
            num = my_getnbr(splitted[i] + 1);
            write(parsing->file_fd, &num, 1);
            res += 1;
        }
        if (parameter_type == T_IND)
            write_params_indirect(
                parsing, splitted, &res, (int *[3]){&num, &i, curr_byte});
        write_params_dir(parsing, splitted, mnemonique,
            (int *[5]){&parameter_type, &i, curr_byte, &mnem_index, &res});
    }
    return res;
}
