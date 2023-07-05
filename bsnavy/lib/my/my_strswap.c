/*
** EPITECH PROJECT, 2021
** my_strswap
** File description:
** no, real programmers use cat
*/

void my_strswap(char **str1, char **str2)
{
    char *temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}
