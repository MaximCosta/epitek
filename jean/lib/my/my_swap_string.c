/*
** EPITECH PROJECT, 2021
** My functions
** File description:
** swap string
*/

void my_swap_string(char **str1, char **str2)
{
    char *str = *str1;

    *str1 = *str2;
    *str2 = str;
}
