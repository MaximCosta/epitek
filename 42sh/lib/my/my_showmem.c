/*
** EPITECH PROJECT, 2021
** B-CPE-100-MPL-1-1-cpoolday06-kilyan.cotten
** File description:
** my_showmem.c
*/

#include <stdio.h>
int my_strlen(char const *s);
int my_putnbr_base(int n, char const *base_tab);
void my_putchar(char c);

static void print_letter(char c)
{
    if (c < 32 || c > 126) {
        my_putchar('.');
    } else {
        my_putchar(c);
    }
}

static void print_hex(int size, int s)
{
    int n = 0;
    int f = size;
    int i;

    while (size) {
        size /= 16;
        n++;
    }
    n = s - n == s ? s - 1 : s - n;
    for (i = 0; i < n; i++) {
        my_putchar('0');
    }
    my_putnbr_base(f, "0123456789abcdef");
}

static void print_hexchars(char const *str, int start, int size)
{
    for (int i = 0; i < 16; i++) {
        if (i + start < size) {
            print_hex(str[start + i], 2);
        } else {
            my_putchar(' ');
            my_putchar(' ');
        }
        if (i % 2)
            my_putchar(' ');
    }
}

static void print_chars(char const *str, int start, int size)
{
    for (int i = 0; i < 16; i++) {
        if (i + start < size) {
            print_letter(str[i + start]);
        }
    }
    my_putchar('\n');
}

int my_showmem(char const *str , int size)
{
    int i;

    for (i = 0; i < size / 16 + 1; i++) {
        if (i * 16 < size) {
            print_hex(i * 16, 8);
            my_putchar(':');
            my_putchar(' ');
            print_hexchars(str, i * 16, size);
            print_chars(str, i * 16, size);
        }
    }
    return size;
}
