/*
** EPITECH PROJECT, 2021
** my_getnbr
** File description:
** returns a number, sent as string
*/

int check_nb(char *str, int ps)
{
    long int rs = 0;
    long int tmp = 0;

    while (*str >= 48 && *str <= 57) {
        tmp = rs * 10;
        tmp += *str - 48;
        if (ps == 1 && tmp > 2147483647)
            return 0;
        if (ps == -1 && tmp > 2147483648)
            return 0;
        rs = tmp;
        str++;
    }
    return (int)(rs * ps);
}

int my_getnbr(char *str)
{
    int ps = 1;

    while (('-' == (*str)) || ((*str) == '+')) {
        if (*str == '-')
            ps = ps * -1;
        str++;
    }
    return check_nb(str, ps);
}
