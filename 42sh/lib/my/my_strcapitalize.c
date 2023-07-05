/*
** EPITECH PROJECT, 2021
** B-CPE-100-MPL-1-1-cpoolday06-kilyan.cotten
** File description:
** my_strcapitalize.c
*/

char *my_strlowcase(char *str);
int is_letter(char c);
int is_number(char c);

static int will_be_upper(char c, char cc)
{
    if (is_letter(c))
        if (!is_letter(cc) && !is_number(cc))
            return 1;
    return 0;
}

char *my_strcapitalize(char *str)
{
    int i = 0;

    my_strlowcase(str);
    while (str[i]) {
        if (i == 0 && is_letter(str[i])) {
            str[i] -= 32;
            i++;
            continue;
        }
        if (will_be_upper(str[i], str[i - 1])) {
            str[i] -= 32;
        }
        i++;
    }
    return (str);
}
