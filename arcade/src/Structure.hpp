/*
** EPITECH PROJECT, 2023
** Object-Oriented Programming |-| Arcade
** File description:
** Just my Structure
*/

#ifndef STRUCTUREHEADER
#define STRUCTUREHEADER

#include <string>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <stdlib.h>
#include <functional>
#include <stdexcept>
#include <dlfcn.h>
#include <stdexcept>
#include <vector>
#include <utility>

namespace arcade
{
    class MyStruct {
        public:
            struct _textToDraw {
                std::vector<int> x;
                std::vector<int> y;
                std::vector<int> xSprite;
                std::vector<int> ySprite;
                std::vector<std::string> text;
                std::vector<std::string> sprites;
                std::vector<std::string> leaderboard;
                std::vector<std::string> map;
                std::string username;
                int death;
                std::function<void(int)> SetInput;
            };
    };
}

#endif /* !STRUCTUREHEADER */
