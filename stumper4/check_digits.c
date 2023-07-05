/*
** EPITECH PROJECT, 2022
** stumper04
** File description:
** check_digits
*/

int check_digits(char *buffer)
{
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n')
            continue;
        if (buffer[i] >= 97 && buffer[i] <= 122)
            continue;
        exit(84);
    }
    return 0;
}
