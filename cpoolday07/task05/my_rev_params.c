/*
** EPITECH PROJECT, 2021
** my_rev_params
** File description:
** Print rev arg
*/

void my_putchar(char);
int my_putstr(char const *str);

int main(int argc, char *argv[])
{
    int i = argc;

    i--;
    for (; i >= 0; i--) {
        my_putstr(argv[i]);
        my_putchar('\n');
    }
    return 0;
}
