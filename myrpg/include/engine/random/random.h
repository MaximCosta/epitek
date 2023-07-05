/*
** EPITECH PROJECT, 2021
** myhunter
** File description:
** myhunter.h
*/
#ifndef RANDOM_H
    #define RANDOM_H
    #define RANDNUM(min, max) ((rand() % (int)(((max) + 1) - (min))) + (min))
    #include "../engine.h"

void random_init(unsigned int seed);

#endif //SCENE_H
