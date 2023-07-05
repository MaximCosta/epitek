/*
** EPITECH PROJECT, 2021
** my_ls [WSL: Ubuntu]
** File description:
** my_revarr
*/

void my_revarr(char *arr[], int n)
{
    char *temp;

    for (int i = 0, j = n - 1; i < j; i++, j--) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
