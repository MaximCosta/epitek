/*
** EPITECH PROJECT, 2023
** nmobjdump [WSL: Ubuntu]
** File description:
** my_objdump
*/

#include "my_objdump.h"

void print_ascii(uint32_t j, uint32_t *z, uchar_t *w, char *t)
{
    for (int x = j; x % 16 != 0; x++) {
        if (x % 4 == 0 && x % 16)
            printf(" ");
        printf("  ");
    }
    printf("  ");
    for (; *z < j; (*z)++)
        if (isprint(w[*z]))
            printf("%c", t[*z]);
        else
            printf(".");
    for (; *z % 16 != 0; (*z)++)
        printf(" ");
    *z = j;
    printf("\n");
}

static int exit_on_error(char *filename, int *fd, long *size, void **data)
{
    if (access(filename, F_OK) == -1) {
        printf("objdump: '%s': No such file\n", filename);
        return 1;
    }
    if ((*fd = open(filename, O_RDONLY, 0)) == -1) {
        fprintf(stderr, "objdump: %s: File format not recognized\n", filename);
        return 1;
    }
    if ((*size = lseek(*fd, 0, SEEK_END)) == -1) {
        fprintf(stderr, "error: lseek: %s\n", strerror(errno));
        return 1;
    }
    if ((*data = mmap(NULL, *size, PROT_READ, MAP_SHARED, *fd, 0))
        == MAP_FAILED) {
        close(*fd);
        fprintf(stderr, "objdump: Warning: '%s' is not an ordinary file\n",
            filename);
        return 1;
    }
    return 0;
}

void my_objdump(char *filename)
{
    void *data;
    Elf32_Ehdr *elf;
    int fd;
    long size;

    if (exit_on_error(filename, &fd, &size, &data))
        return;
    elf = (Elf32_Ehdr *) data;
    if (elf->e_ident[EI_CLASS] == ELFCLASS32)
        f32(data, filename);
    else if (elf->e_ident[EI_CLASS] == ELFCLASS64)
        f64(data, filename);
    else
        fprintf(stderr, "objdump: %s: File format not recognized\n", filename);
    if (close(fd) == -1)
        fprintf(stderr, "error: munmap: %s\n", strerror(errno));
    if (munmap(data, size) == -1)
        fprintf(stderr, "error: munmap: %s\n", strerror(errno));
}

int main(int ac, char **av)
{
    if (ac > 1)
        for (int i = 0; ++i < ac;)
            my_objdump(av[i]);
    else
        my_objdump("./a.out");
    return (0);
}
