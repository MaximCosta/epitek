/*
** EPITECH PROJECT, 2021
** my_strncmp
** File description:
** there's a problem: the intra is not down
*/

int my_strncmp(char const* s1, char const* s2, int n)
{
    int i = 0;

    while(i < n) {
        if (s1[i] == '\0')
            return 0;
        else if (s1[i] < s2[i])
            return -1;
        else
            return 1;
        i++;
    }
    return 0;
}
