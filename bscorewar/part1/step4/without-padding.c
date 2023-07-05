/*
** EPITECH PROJECT, 2022
** bscorewar [WSL: Ubuntu]
** File description:
** without-padding
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *fp = fopen("several-variables.yolo", "w");
    int value = 192837;
    char chars[40] = {0};

    strcpy(chars, "Corewar is swag!!");
    return 0 * fwrite((const void *) &value, sizeof(int), 1, fp)
        * fprintf(fp, "%c", 'k') * fwrite(&chars, sizeof(char), 40, fp);
}