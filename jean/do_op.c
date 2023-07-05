/*
** EPITECH PROJECT, 2021
** bistro_matic
** File description:
** op
*/

#include <stdlib.h>
#include "bistromatic.h"

char *do_mod(char *nb1, char *nb2, opbase_t opbase)
{
    switch (neg_numbers(&nb1, &nb2, opbase)) {
        case 1 : return infin_mod(nb1 + 1, nb2, NEGATIF, opbase);
        case 2 : return infin_mod(nb1, nb2 + 1, POSITIF, opbase);
        case 3 : return infin_mod(nb1 + 1, nb2 + 1, NEGATIF, opbase);
    }
    return infin_mod(nb1, nb2, POSITIF, opbase);
}

char *do_div(char *nb1, char *nb2, opbase_t opbase)
{
    switch (neg_numbers(&nb1, &nb2, opbase)) {
        case 1 : return infin_div(nb1 + 1, nb2, NEGATIF, opbase);
        case 2 : return infin_div(nb1, nb2 + 1, NEGATIF, opbase);
        case 3 : return infin_div(nb1 + 1, nb2 + 1, POSITIF, opbase);
    }
    return infin_div(nb1, nb2, POSITIF, opbase);
}

char *do_mul(char *nb1, char *nb2, opbase_t opbase)
{
    switch (neg_numbers(&nb1, &nb2, opbase)) {
        case 1 : return infin_mul(nb1 + 1, nb2, NEGATIF, opbase);
        case 2 : return infin_mul(nb1, nb2 + 1, NEGATIF, opbase);
        case 3 : return infin_mul(nb2 + 1, nb1 + 1, POSITIF, opbase);
    }
    return infin_mul(nb1, nb2, POSITIF, opbase);
}

char *do_sub(char *nb1, char *nb2, opbase_t opbase)
{
    switch (neg_numbers(&nb1, &nb2, opbase)) {
        case 1 : return infin_add(nb1 + 1, nb2, NEGATIF, opbase);
        case 2 : return infin_add(nb1, nb2 + 1, POSITIF, opbase);
        case 3 : return infin_sub(nb2 + 1, nb1 + 1, opbase);
    }
    return infin_sub(nb1, nb2, opbase);
}

char *do_add(char *nb1, char *nb2, opbase_t opbase)
{
    switch (neg_numbers(&nb1, &nb2, opbase)) {
        case 1 : return infin_sub(nb2, nb1 + 1, opbase);
        case 2 : return infin_sub(nb1, nb2 + 1, opbase);
        case 3 : return infin_add(nb1 + 1, nb2 + 1, NEGATIF, opbase);
    }
    return infin_add(nb1, nb2, POSITIF, opbase);
}
