/*
** EPITECH PROJECT, 2023
** nmobjdump [WSL: Ubuntu]
** File description:
** my_objdump
*/

#ifndef MY_OBJDUMP_H_
    #define MY_OBJDUMP_H_
    #include <ctype.h>
    #include <elf.h>
    #include <errno.h>
    #include <fcntl.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <sys/mman.h>
    #include <unistd.h>
    typedef unsigned char uchar_t;
    void f32(void *data, char *filename);
    void f64(void *data, char *filename);
    void print_ascii(uint32_t j, uint32_t *z, uchar_t *w, char *t);
#endif /* !MY_OBJDUMP_H_ */
