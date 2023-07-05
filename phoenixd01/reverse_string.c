/*
** EPITECH PROJECT, 2021
** B-BOO-101-MPL-1-1-phoenixd01-maxim.costa [WSL: Ubuntu]
** File description:
** reverse_string
*/

void my_putchar(char c);

char *reverse_string(char *str)
{
    int i1 = 0;
    int i2 = 0;
    char tmp;

    for (; str[i1]; i1++);
    i1--;
    for (; i1 > i2; i2++, i1--) {
        tmp = str[i2];
        str[i2] = str[i1];
        str[i1] = tmp;
    }
    return str;
}
