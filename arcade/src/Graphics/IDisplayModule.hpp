/*
** EPITECH PROJECT, 2023
** Object-Oriented Programming |-| Arcade
** File description:
** Interface Class
*/

#ifndef IDISPLAYMODULEHEADER
#define IDISPLAYMODULEHEADER

#include <string>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <stdlib.h>
#include <stdexcept>
#include <dlfcn.h>
#include <stdexcept>
#include <vector>
#include <utility>

// Ncurses include
#include <curses.h>
#include <ncurses.h>

// SFML Include
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "../Structure.hpp"

namespace arcade
{
    class IDisplayModule {
        public:
            virtual ~IDisplayModule() = default;

            virtual void Init() = 0;
            virtual void LoadStruct(MyStruct::_textToDraw textDisplay) = 0;
            virtual void InitColor() = 0;

            virtual void DisplayHome() = 0;
            virtual void DisplayParsing() = 0;
            virtual void DisplayMap() = 0;
            virtual void DisplayPlayer(std::pair<std::vector<int>, std::vector<int>>) = 0;
            virtual void DisplayOther(int score) = 0;

            virtual std::string Command() = 0;
            virtual std::string GamesCommand() = 0;
            virtual int SetUsername() = 0;
            virtual void QuitArcade() = 0;

        protected:
        private:
    };
}

#endif /* !IDISPLAYMODULEHEADER */
