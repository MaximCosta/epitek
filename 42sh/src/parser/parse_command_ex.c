/*
** EPITECH PROJECT, 2021
** B-PSU-210-MPL-2-1-42sh-kilyan.cotten
** File description:
** parse_command_ex.c
*/

#include "mysh.h"

int test_parse(char *str, char **to_parse)
{
    for (int i = 0; to_parse[i]; i++) {
        if (!strncmp(str, to_parse[i], strlen(to_parse[i])))
            return i;
    }
    return -1;
}

static int sum_all(int *tab, int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++)
        sum += tab[i];
    return sum;
}

static int number_to_next_parse_get_error(int *tab)
{
    for (int i = 0; i < 3; i++) {
        if (tab[i] != 0)
            return UNMACHED_SQUOTE + i;
    }
    return 0;
}

int number_to_next_parse(char *str, char **to_parse)
{
    int parentesis = 0;
    int tab[3] = {0, 0, 0};
    char tab_char[4] = "`\"'";
    int i = 0;

    for (i = 0; str[i]; i++) {
        if (!sum_all(tab, 3) && ((str[i] == '(' || str[i] == ')')))
            parentesis += str[i] == '(' ? 1 : -1;
        if (parentesis < 0)
            return -2 + (long int) SH_SETERROR(TOOMANY_PARENTESIS_LEFT) * 0;
        if (get_index(tab_char, str[i]) != -1)
            tab[get_index(tab_char, str[i])] ^= 1;
        if (!parentesis && !sum_all(tab, 3) &&
            test_parse(str + i, to_parse) != -1) {
            return i;
        }
    }
    if (parentesis || sum_all(tab, 3))
        return (long int)SH_SETERROR(parentesis ? TOOMANY_PARENTESIS_RIGHT :
        number_to_next_parse_get_error(tab)) * 0 - 2;
    return -1;
}

command_t *minishell_parser_commands_cleanstr(command_t *head)
{
    command_t *tmp_head = head;

    if (!head)
        return NULL;
    while (head) {
        head->command = clean_my_str(head->command);
        head = head->next;
    }
    return tmp_head;
}