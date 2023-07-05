/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 05
*/

#include "stringcontainer.h"
#include "../../new.h"
#include "string.h"
#include "int.h"

int main(void)
{
    Object *stro = new (String, "Hello World !");
    Object *str2 = new (String, "Toutou");

    printf("%d\n", empty(stro));
    printf("%zu\n", len(stro));
    printf("%s\n", str(addition(stro, stro)));
    printf("%s\n", str(multiplication(stro, new(Int, 3))));
    printf("%s\n", str(append(stro, str2)));
    print(stro);
    delete(stro);
}
