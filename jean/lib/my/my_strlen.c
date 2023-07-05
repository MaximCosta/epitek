/*
** EPITECH PROJECT, 2021
** Pool Day04
** File description:
** My_strlen
*/

int my_strlen(char const *str)
{
    int cpt = 0;

    while (*str != '\0') {
        cpt++;
        str++;
    }
    return (cpt);
}
