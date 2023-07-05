/*
** EPITECH PROJECT, 2021
** my_evil_str
** File description:
** write word and reverse word
*/

int my_strlen(char const *str);

char *my_evil_str(char *str)
{
    int z = my_strlen(str) - 1;
    int x = 0;
    char t;

    while (x < z) {
        t = str[x];
        str[x] = str[z];
        str[z] = t;
        x++;
        z--;
    }
    return str;
}
