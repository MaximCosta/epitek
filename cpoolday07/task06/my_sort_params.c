/*
** EPITECH PROJECT, 2021
** my_sort_params
** File description:
** Sort arg
*/

void my_putchar(char c);
int my_putstr(char const* str);
char* my_strcpy(char* dest, char const* src);
int my_strcmp(char const* s1, char const* s2);

void my_swap_str(char** s1, char** s2)
{
    char* tmp;

    tmp = *s1;
    *s1 = *s2;
    *s2 = tmp;
}

char **my_sort_params(int argc, char **argv)
{
    int i = 0;
    while (i < argc - 1) {
        if (my_strcmp(argv[i], argv[i + 1]) > 0) {
            my_swap_str(&argv[i], &argv[i + 1]);
            i = 0;
        }
        i++;
    }
    return argv;
}

int main(int argc, char **argv)
{
    char **test = my_sort_params(argc, argv);
    for (int i = 0; i<argc; i++) {
        my_putstr(test[i]);
        my_putchar('\n');
    }
    return 0;
}
