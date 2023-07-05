/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-bsnavy-maxim.costa [WSL: Ubuntu]
** File description:
** kill_it
*/

#include "my.h"
#include <signal.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
    if (argc != 2) return 0;
    kill(my_getnbr(argv[1]), SIGQUIT);
    return 0;
}