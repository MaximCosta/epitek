/*
** EPITECH PROJECT, 2021
** B-BOO-101-MPL-1-1-phoenixd02-maxim.costa [WSL: Ubuntu]
** File description:
** my_strncmp
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    for (; (s1[i] == s2[i]) && (i < n); i++)
        if (s1[i] == '\0')
            return (0);
    if ((s1[i] == '\0' && s2[i] == '\0') || i == n)
        return 0;
    else if (s1[i] == '\0' || s1[i] < s2[i])
        return -1;
    else
        return 1;
}