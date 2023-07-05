/*
** EPITECH PROJECT, 2021
** my_getnbr2.c
** File description:
** my get number second part
*/

int my_strlen(const char *s);
int is_number(char c);
int is_lower(char c);

int get_start(char const *str)
{
    int i = 0;

    while (i < my_strlen(str) - 1) {
        if (is_number(str[i]) || !is_lower(str[i]))
            return i;
        i++;
    }
    return i;
}

int is_equal(char c)
{
    return c == '-' || c == '+' ? 1 : 0;
}

int get_index(char const *str, char c)
{
    int i = 0;

    while (str[i]) {
        if (str[i] == c)
            return i;
        i++;
    }
    return -1;
}
