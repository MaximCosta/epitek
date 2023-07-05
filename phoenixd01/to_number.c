/*
** EPITECH PROJECT, 2021
** B-BOO-101-MPL-1-1-phoenixd01-maxim.costa [WSL: Ubuntu]
** File description:
** to_number
*/

static int get_nbr(char *str, int ps)
{
    long int rs = 0;
    long int max_tmp;

    for (;48 <= *str && *str <= 57; str++, rs = max_tmp) {
        max_tmp = rs * 10;
        max_tmp += *str - 48;
        if (ps == 1 && max_tmp > 2147483647)
            return 0;
        if (ps == -1 && max_tmp > 2147483648)
            return 0;
    }
    return (int)(rs * ps);
}

int to_number(char *str)
{
    int ps = 1;

    for (;('-' == (*str)) || ((*str) == '+'); str++)
        if (*str == '-')
            ps = ps * -1;
    return get_nbr(str, ps);
}
