/*
** EPITECH PROJECT, 2022
** antman [WSL: Ubuntu]
** File description:
** bin_to_int
*/

int my_strlen(char const *str);
int my_pow(int nb, int power);

int bin_to_int(char *bin)
{
    int res = 0;
    int pos = 0;

    for (int index = my_strlen(bin) - 1; index >= 0; index--) {
        res = res + (bin[index] - 48) * my_pow(2, pos);
        pos++;
    }
    return res;
}
