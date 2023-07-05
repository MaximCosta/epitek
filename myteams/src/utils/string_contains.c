/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myftp-hades.cuisinier
** File description:
** string_contains
*/

int string_contains(char *str, char c)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == c)
            return 1;
    return 0;
}
