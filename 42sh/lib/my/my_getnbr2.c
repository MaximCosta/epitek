/*
** EPITECH PROJECT, 2021
** my_getnbr2.c
** File description:
** my get number second part
*/

int my_strlen(const char *s);
int is_number(char c);

int get_nbr_get_start(char const *str)
{
    int i = 0;

    while (i < my_strlen(str) - 1) {
        if (is_number(str[i]))
            return i;
        i++;
    }
    return i;
}
