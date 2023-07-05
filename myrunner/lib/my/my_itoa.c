/*
** EPITECH PROJECT, 2021
** test [SSH: 192.168.177.128]
** File description:
** my_itoa
*/

static int abs(int value)
{
    if (value < 0)
        return -value;
    return value;
}

static void swap(char *x, char *y)
{
    char t = *x;
    *x = *y;
    *y = t;
}

static char *reverse(char *buffer, int i, int j)
{
    for (;i < j;)
        swap(&buffer[i++], &buffer[j--]);
    return buffer;
}

char *my_itoa(int value, char *buffer, int base)
{
    int n = abs(value);
    int i = 0;
    int r;

    if (base < 2 || base > 32)
        return buffer;
    while (n) {
        r = n % base;
        if (r >= 10)
            buffer[i++] = 65 + (r - 10);
        else
            buffer[i++] = 48 + r;
        n /= base;
    }
    if (i == 0)
        buffer[i++] = '0';
    if (value < 0 && base == 10)
        buffer[i++] = '-';
    buffer[i] = '\0';
    return reverse(buffer, 0, i - 1);
}
