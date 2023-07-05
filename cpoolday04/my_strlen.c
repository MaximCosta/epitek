/*
** EPITECH PROJECT, 2021
** my_strlen
** File description:
** get len of array
*/

int my_strlen(char const *str)
{
    int i = 0;
    char val = *(str + i);

    while (val) {
        val = *(str + ++i);
    }
    return i;
}
