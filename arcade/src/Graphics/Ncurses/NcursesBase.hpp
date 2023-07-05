/*
** EPITECH PROJECT, 2023
** Object-Oriented Programming |-| Arcade
** File description:
** NcursesBase hpp
*/

#ifndef NCURSESBASEHEADER
#define NCURSESBASEHEADER

#include "../IDisplayModule.hpp"

#define L LINES
#define C COLS

namespace arcade
{
    class NcursesBase : public IDisplayModule {
        public:
            NcursesBase();
            ~NcursesBase();

            void Init();
            void LoadStruct(MyStruct::_textToDraw textDisplay);
            void InitColor();

            void DisplayHome();
            void DisplayParsing();
            void DisplayMap();
            void DisplayPlayer(std::pair<std::vector<int>, std::vector<int>>);
            void DisplayOther(int score);

            std::string Command();
            std::string GamesCommand();
            int SetUsername();
            void QuitArcade();

        protected:
            MyStruct::_textToDraw _textDisplay;

            int _c;
            int _state;
            int _game;
            int _gameLaunch;

        private:
    };
}

#endif /* !NCURSESBASEHEADER */
