/*
** EPITECH PROJECT, 2022
** anagram
** File description:
** man man
*/

#include <unistd.h>

int len(char const *str)
{
    int i;

    for (i = 0; str[i]; i++);
    return i;
}

int print(char const *str)
{
    int out = write(1, str, len(str));

    if (out < 0)
        return 84;
    return 0;
}

int err(void)
{
    int out = write(2, "Error: not enough arguments.\n", 29);
    if (out < 0)
        return 84;
    return 84;
}

int include(char c, char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == c) {
            str[i] = 1;
            return 1;
        }
    }
    return 0;
}

int main(int ac, char *av[])
{
    if (ac < 3)
        return err();
    if (len(av[1]) != len(av[2]))
        return print("no anagrams.\n");
    for (int i = 0; av[1][i]; i++) { 
        if ('A' <= av[1][i] && av[1][i] <= 'Z')
            av[1][i] += 32;
        if ('A' <= av[2][i] && av[2][i] <= 'Z')
            av[2][i] += 32;
    }
    for (int i = 0; av[1][i]; i++)
        if (!include(av[1][i], av[2]))
            return print("no anagrams.\n");
    print("anagram!\n");
    return 0;
}

