/*
** EPITECH PROJECT, 2021
** Pool Day06
** File description:
** my_strcmp
*/

int my_strcmp(char const *s1, char const *s2)
{
    while (*s1 != '\0' && *s1 == *s2) {
        s1++;
        s2++;
    }
    if (*s1 == *s2) {
        return (0);
    } else if (*s1 > *s2) {
        return (*s1);
    } else {
        return (- *s2);
    }
}
