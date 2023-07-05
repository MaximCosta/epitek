/*
** EPITECH PROJECT, 2021
** /home/maxim/epitech_project/delivery/B-CPE-100-MPL-1-1-cpoolday05-maxim.costa/my_compute_power_it
** File description:
** power iterative
*/

int my_compute_power_it(int nb, int p)
{
    int res = 1;

    if (p < 0)
        return 0;
    if (p == 0)
        return 1;
    if (p == 1)
        return nb;
    while (p >= 1) {
        res *= nb;
        p--;
    }
    return res;
}
