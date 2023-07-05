/*
** EPITECH PROJECT, 2021
** Pool day06
** File description:
** My_strncmp
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    while (*s1 != '\0' && *s1 == *s2 && n > 0) {
        s1++;
        s2++;
        n--;
    }
    if (n == 0) {
        s1--;
        s2--;
    }
    if (*s1 == *s2) {
        return (0);
    } else if (*s1 > *s2) {
        return (*s1);
    } else {
        return (- *s2);
    }
}
