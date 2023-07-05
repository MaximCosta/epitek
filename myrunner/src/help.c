/*
** EPITECH PROJECT, 2021
** test [SSH: 192.168.177.128]
** File description:
** help
*/

#include "game.h"
#include "my.h"
#include "my_printf.h"

int help(int stat)
{
    if (!stat) {
        my_printf("./my_runner: bad arguments: 0 given but 1 is required\n");
        my_printf("retry with -h\n");
        return (84);
    } else {
        my_printf("Finite runner created with CSFML.\n\n");
        my_printf("USAGE");
        my_printf("\t./my_runner map.txt\n\n");
        my_printf("OPTIONS\n");
        my_printf("\t-i launch the game in infinity mode.\n");
        my_printf("\t-h print the usage and quit.\n\n");
        my_printf("USER INTERACTIONS\n");
        my_printf("\tSPACE_KEY jump.\n");
        return (0);
    }
}
