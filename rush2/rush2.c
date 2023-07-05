/*
** EPITECH PROJECT, 2021
** rush2
** File description:
** find lang
*/

#include "include/my.h"

int get_char_value(char letter)
{
    if (LET1(letter))
        return letter + 32 - 97;
    return letter - 97;
}

int get_length(struct let_info* p, char letter)
{
    if (LET(letter) || LET1(letter)) {
        return p[get_char_value(letter)].length;
    }
    return -1;
}

int score_language(int ac, char **av, float *score)
{
    float global_score[4] = { 0.0 };
    char *lang[4] = { "English", "French", "German", "Spanish" };

    for (int s = 0; s < 4; s++) {
        for (int i = 0; i + 2 < ac; i++) {
            global_score[s] += (score[i] / get_lang_val(s, av[i + 2][0]));
        }
    }
    my_putstr("=> ");
    my_putstr(lang[find_minimum(global_score, 4)]);
    return 0;
}

int print_score(int ac, char **av, float *score, int count, struct let_info *p)
{
    int len = 0;
    int p2 = 0;

    for (int i = 0; i + 2 < ac; i++) {
        len = get_length(p, av[i + 2][0]);
        score[i] = (float)len / (float)count * 100;
        p2 = len * 100 % count * 100 / count;
        my_putchar(av[i + 2][0]);
        my_putchar(':');
        my_put_nbr(len);
        my_putstr(" (");
        my_put_nbr(len * 100 / count);
        my_putchar('.');
        if (p2 < 10)
            my_putchar('0');
        my_put_nbr(p2);
        my_putstr("%)\n");
    }
    return score_language(ac, av, score);
}

int main(int ac, char **av)
{
    struct let_info p[26] = { 0 };
    float score[ac];
    int count = 0;

    for (int i = 0; i < 26; i++) {
        p[i].letter = i + 97;
        p[i].length = 0;
    }
    for (int i = 0; av[1][i]; i++) {
        if (LET(av[1][i]) || LET1(av[1][i])) {
            p[get_char_value(av[1][i])].length++;
            count++;
        }
    }
    print_score(ac, av, score, count, p);
    return 0;
}
