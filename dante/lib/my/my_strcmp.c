/*
** EPITECH PROJECT, 2021
** navy
** File description:
** my_strcmp
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int j = 0;

    while (s1[i] == s2[j] && s1[i] != '\0') {
        i++;
        j++;
    }
    if (s1[i] != s2[j]) {
        if (s1[i] > s2[j])
            return 1;
        else if (s1[i] < s2[j])
            return -1;
        else
            return 0;
    }
    return 0;
}
