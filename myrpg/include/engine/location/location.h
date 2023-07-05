/*
** EPITECH PROJECT, 2021
** myhunter
** File description:
** myhunter.h
*/
#ifndef LOCATION_H
    #define LOCATION_H

typedef struct s_location loc_t ;

struct s_location {

    float x;
    float y;

};

loc_t  location_create(float x, float y);

#endif //LOCATION_H
