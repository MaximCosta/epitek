/*
** EPITECH PROJECT, 2021
** My  functions
** File description:
** nbr_line_char_tab
*/

int nbr_line_char_tab(char **words)
{
    int cpt = 0;
    char **begin = words;

    while (*words) {
        cpt++;
        words++;
    }
    words = begin;
    return cpt;
}
