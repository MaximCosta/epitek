/*
** EPITECH PROJECT, 2023
** nmobjdump [WSL: Ubuntu]
** File description:
** f32
*/

#include "my_objdump.h"

void p32(char *strtab, Elf32_Ehdr *elf, Elf32_Shdr *shdr, int i)
{
    uint32_t j = 0;
    uint32_t z = 0;
    uint32_t addr = shdr[i].sh_addr;
    uchar_t *w = (uchar_t *) ((char *) elf + shdr[i].sh_offset);

    printf("Contents of section %s:\n", &strtab[shdr[i].sh_name]);
    while (j < shdr[i].sh_size) {
        if (j % 16 == 0)
            printf(" %04x ", addr);
        printf("%02x", w[j++]);
        if (j % 4 == 0 && j % 16 && j < shdr[i].sh_size)
            printf(" ");
        if (j % 16 == 0)
            addr += 16;
        if (j % 16 == 0 || j >= shdr[i].sh_size)
            print_ascii(j, &z, w, (char *) w);
    }
}

void s32(char *strtab, Elf32_Ehdr *elf, Elf32_Shdr *shdr)
{
    for (int i = -1; ++i < elf->e_shnum;) {
        if (shdr[i].sh_size && strcmp(&strtab[shdr[i].sh_name], ".strtab")
            && strcmp(&strtab[shdr[i].sh_name], ".symtab")
            && strcmp(&strtab[shdr[i].sh_name], ".shstrtab")
            && strcmp(&strtab[shdr[i].sh_name], ".bss")) {
            p32(strtab, elf, shdr, i);
        }
    }
}

void f32(void *data, char *filename)
{
    Elf32_Ehdr *elf = (Elf32_Ehdr *) data;
    Elf32_Shdr *shdr;
    char *strtab;

    if (elf->e_ident[EI_MAG0] != ELFMAG0 || elf->e_ident[EI_MAG1] != ELFMAG1
        || elf->e_ident[EI_MAG2] != ELFMAG2 || elf->e_ident[EI_MAG3] != ELFMAG3
        || (elf->e_type != ET_EXEC && elf->e_type != ET_REL
            && elf->e_type != ET_DYN)) {
        fprintf(stderr, "objdump: %s: File format not recognized\n", filename);
        return;
    }
    shdr = (Elf32_Shdr *) (data + elf->e_shoff);
    strtab = (char *) (data + shdr[elf->e_shstrndx].sh_offset);
    printf("\n%s:%5cfile format elf32-i386\n", filename, ' ');
    printf("architecture: i386, flags 0x%08x:\n", elf->e_flags);
    printf("HAS_SYMS, DYNAMIC, D_PAGED\n");
    printf("start address 0x%08x\n\n", elf->e_entry);
    s32(strtab, elf, shdr);
}
