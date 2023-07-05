/*
** EPITECH PROJECT, 2022
** main
** File description:
** check your malloc!
*/

#include "solo.h"

int compare(char const *s1, char const *s2)
{
    for (int i = 0; 1; i++) {
        if (DOWN(s1[i]) > DOWN(s2[i])) return 1;
        if (DOWN(s1[i]) < DOWN(s2[i])) return -1;
        if (DOWN(s1[i]) == '\0') return 0;
    }
}

int print(char **av, char *a, int i)
{
    if (av == NULL) {
        for (; *a; a++) write(1, &a[0], 1);
        return 1;
    }
    for (int j = 0; j <= i; j++) {
        if (j != 0) write(1, " ", 1);
        for (int k = 0; av[j][k]; write(1, &av[j][k++], 1));
    }
    write(1, "\n", 1);
    return 0;
}

char **check(char **av, int count)
{
    char *tmp;

    for (int i = 0 ; i != count; i++) {
        if (compare(av[i], av[i + 1]) == 1) {
            tmp = av[i];
            av[i] = av[i + 1];
            av[i + 1] = tmp;
            i = 0;
        };
    }
    return av;
}

int main(int ac, char **av)
{
    char **arr;
    int count = 0;
    int val = 0;

    if (ac == 1 && print(NULL, "\n", 0)) return 0;
    for (; spaces(*av[1]); av[1]++);
    if (!(*av[1]) && print(NULL, "\n", 0)) return 0;
    for (int i = 1; av[1][i]; i++)
        if (!space(av[1][i]) && space(av[1][i - 1])) count++;
    arr = malloc((count + 2) * sizeof(char*));
    arr[val++] = av[1];
    for (av[1]++; *av[1]; av[1]++) {
        if (!space(*av[1]) && space(*(av[1] - 1))) arr[val++] = av[1];
        if (space(*av[1])) *av[1] = '\0';
    }
    print(check(arr, count), "", count);
    free(arr);
    return 0;
}
