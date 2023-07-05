/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD04am-maxim.costa [WSL: Ubuntu]
** File description:
** mul_div
*/

void mul_div_long(int a, int b, int *mul, int *div)
{
    if (b != 0) {
        *mul = a * b;
        *div = a / b;
    } else {
        *mul = 0;
        *div = 42;
    }
}

void mul_div_short(int *a, int *b)
{
    int mul_res = *a * *b;
    int div_res = (*b != 0) ? (*a / *b) : 42;
    *a = mul_res;
    *b = div_res;
}
