/*
** EPITECH PROJECT, 2021
** test [SSH: 192.168.177.128]
** File description:
** my_atoi
*/

int my_atoi(const char *str)
{
    int imax = 2147483647;
    int imin = -2147483648;
    int sign = 1;
    int bs = 0;
    int i = 0;

    for (; str[i] == ' '; i++);
    if (str[i] == '-' || str[i] == '+')
        sign = 1 - 2 * (str[i++] == '-');
    for (; '0' <= str[i] && str[i] <= '9'; bs = 10 * bs + (str[i++] - '0'))
        if (bs > imax / 10 || (bs == imax / 10 && str[i] - '0' > 7))
            return sign == 1 ? imax : imin;
    return bs * sign;
}
