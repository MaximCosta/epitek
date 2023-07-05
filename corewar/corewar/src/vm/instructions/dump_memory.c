/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** dump_memory.c
*/

#include "../../../include/corewar.h"

int my_putnbr_base(int n, char const *base_tab)
{
    int base = my_strlen(base_tab);

    if (n < 0) {
        my_putchar('-');
        if (n / base)
            my_putnbr_base(-(n / base), base_tab);
        my_putchar(base_tab[-(n % base)]);
        return 0;
    }
    if (n) {
        if (n / base) {
            my_putnbr_base(n / base, base_tab);
        }
    }
    my_putchar(base_tab[n % base]);
    return 0;
}

void dump_memory(corewar_t *corewar)
{
    vm_t *vm = corewar->vm;
    int cell = 0;

    for (int i = 0; i < MEM_SIZE / 32; i++) {
        my_putnbr_base(i * 32, "0123456789ABCDEF");
        my_printf("%s%s%s : ", (i * 32) / 16 == 0 ? " " : "",
            (i * 32) / (16 * 16) == 0 ? " " : "",
            (i * 32) / (16 * 16 * 16) == 0 ? " " : "");
        for (int j = 0; j < 32; j++) {
            my_putstr(vm->fields[i * 32 + j].value < 16 ? "0" : "");
            my_putnbr_base(vm->fields[i * 32 + j].value, "0123456789ABCDEF");
            my_putchar(j == 31 ? '\n' : ' ');
        }
    }
    exit(0);
}
