/*
** EPITECH PROJECT, 2021
** B-CPE-100-MPL-1-1-cpoolday06-kilyan.cotten
** File description:
** my_strcmp.c
*/

int my_strlen(const char *s);

int my_strcmp(char const *s1 , char const *s2)
{
    int i = 0;

    while (s1[i] && s2[i]) {
        if (s1[i] > s2[i])
            return s1[i] - s2[i];
        if (s1[i] < s2[i])
            return s1[i] - s2[i];
        i++;
    }
    if (s1[i] > s2[i])
        return my_strlen(s1) - my_strlen(s2);
    if (s1[i] < s2[i])
        return my_strlen(s1) - my_strlen(s2);
    return 0;
}
