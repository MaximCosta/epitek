/*
** EPITECH PROJECT, 2021
** my_ls [WSL: Ubuntu]
** File description:
** ls_sort
*/

#include "my_ls.h"
#include "my_printf.h"

void sort_time(files_t *arr, int n)
{
    int i = 0;
    files_t temp;

    while (i + 1 < n) {
        if (arr[i + 1].st.st_mtime > arr[i].st.st_mtime) {
            temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
            i = 0;
        }
        i++;
    }
}

void revarr_t(files_t *arr, int n)
{
    files_t temp;
    int j = n - 1;

    for (int i = 0; i < j; i++) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        j--;
    }
}

char *concat_str(char const *str1, char const *str2)
{
    int size1 = my_strlen(str1);
    int size2 = my_strlen(str2);
    char *str = my_calloc(sizeof(char), '\0', size1 + size2 + 2);
    int index = 0;

    for (int i = 0; i < size1; i++)
        str[index++] = str1[i];
    if (str1[size1] != '/')
        str[index++] = '/';
    for (int i = 0; i < size2; i++)
        str[index++] = str2[i];
    return str;
}

void error(void)
{
    if (errno == EACCES)
        my_exit(84, "Permission denied\n");
    if (errno == ENOENT)
        my_exit(84, "Directory does not exist\n");
    if (errno == ENOTDIR)
        my_exit(84, "is not a directory\n");
}
