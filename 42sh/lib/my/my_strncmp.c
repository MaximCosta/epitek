/*
** EPITECH PROJECT, 2021
** B-CPE-100-MPL-1-1-cpoolday06-kilyan.cotten
** File description:
** my_strncmp.c
*/

int my_strlen(const char *str);

int my_strncmp(char const *s1 , char const *s2, int n)
{
    int i = 0;

    while (s1[i] && s2[i] && i < n) {
        if (s1[i] > s2[i])
            return s1[i] - s2[i];
        if (s1[i] < s2[i])
            return s1[i] - s2[i];
        i++;
    }
    if (!s1[i])
        return -s2[i];
    if (!s2[i])
        return s1[i];
    return 0;
}
