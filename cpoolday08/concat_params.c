/*
** EPITECH PROJECT, 2021
** concat_params
** File description:
** show param
*/

#include <stdlib.h>

int my_strlen(char const *str);
int my_putstr(char const *str);
void my_putchar(char c);

int len_array(int argc, char *argv[])
{
    int len = 0;

    for (int i = 0; i < argc; i++) {
        len += my_strlen(argv[i]) + 1;
    }
    return len;
}

char *concat_params(int argc, char *argv[])
{
    int len = len_array(argc, argv);
    int j = 0;
    int n = 0;
    char *dest = NULL;

    dest = malloc(sizeof(char) * (len + 1));
    for (int i = 0; i < argc; i++) {
        j = 0;
        while (argv[i][j]) {
            dest[n] = argv[i][j];
            n++;
            j++;
        }
        if (i < argc - 1)
            dest[n] = '\n';
        n++;
    }
    dest[n] = '\0';
    return dest;
}
