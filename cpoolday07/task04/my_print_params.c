/*
** EPITECH PROJECT, 2021
** my_print_params
** File description:
** Print param
*/

void my_putchar(char c);
int my_putstr(char const *str);

int main(int argc, char *argv[])
{
    for (int i = 0; i < argc; i++) {
        my_putstr(argv[i]);
        my_putchar('\n');
    }
    return 0;
}
