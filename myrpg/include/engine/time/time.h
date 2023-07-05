/*
** EPITECH PROJECT, 2021
** myhunter
** File description:
** myhunter.h
*/
#ifndef TIME_H
    #define TIME_H
    #include "../engine.h"

    typedef struct s_deltatime DeltaTime;

struct s_deltatime {

    float time;
    float saved;

};

void get_elapsed_time(float *time, float *save);
bool elapsed_time_milliseconds(float milliseconds,
float *time, float *save);
bool elapsed_time_microseconds(float microseconds,
float *time, float *save);


#endif //TIME_H
