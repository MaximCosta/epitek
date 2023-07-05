/*
** EPITECH PROJECT, 2021
** my_is_printable
** File description:
** return 1 if char is printable
*/

int is_printable(char c)
{
    if (c > 31 && c < 127)
        return (1);
    return (0);
}
