/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/
#include "../include/asm.h"

int main(int argc, char **argv)
{
    char *file_name;
    parsing_t *parsing = my_calloc(sizeof(parsing_t));

    if (argc == 2) {
        if (my_strcmp(argv[1], "-h") == 0) {
            my_printf("%s",
                "USAGE\n./myasm file_name[.s]\nDESCRIPTION\nfile_name "
                "file in assembly language to be converted into "
                "file_name.cor, an\n"
                "executable in the Virtual Machine.");
            return 0;
        }
        file_name = argv[1];
        if (!has_file_extension(file_name, ".s"))
            return 84;
        compile_asm(argv[1], parsing);
        close(parsing->file_fd);
        return 0;
    }
    return 84;
}
