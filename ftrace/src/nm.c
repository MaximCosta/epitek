/*
** EPITECH PROJECT, 2023
** B_PSU_400_MPL_4_1_FTRACE_HUGO_ESCHLIMANN_NM_C
** File description:
** nm
*/

#include "../include/ftrace.h"

nm_t *init_nm_struct(void)
{
    nm_t *nm = malloc(sizeof(nm_t));

    nm->fd = 0;
    nm->elf = NULL;
    nm->scn = NULL;
    nm->data = NULL;
    nm->name = NULL;
    nm->list = NULL;
    return nm;
}

bool error_handling_elf_file(nm_t *nm, char *filename)
{
    if (elf_version(EV_CURRENT) == EV_NONE) {
        return exit_message("Failed to initialize the libelf library.\n");
    }
    nm->fd = open(filename, O_RDONLY);
    if (nm->fd < 0) {
        return exit_message("Failed to open file.\n");
    }
    nm->elf = elf_begin(nm->fd, ELF_C_READ, NULL);
    if (!nm->elf) {
        return exit_message("Failed to read ELF file.\n");
    }
    return true;
}

bool start_nm(nm_t *nm, char *filename)
{
    if (!error_handling_elf_file(nm, filename)) return false;
    return true;
}
