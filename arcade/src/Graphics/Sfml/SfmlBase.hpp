/*
** EPITECH PROJECT, 2023
** Object-Oriented Programming |-| Arcade
** File description:
** SfmlBase hpp
*/

#ifndef SFMLBASEHEADER
#define SFMLBASEHEADER

#include "../IDisplayModule.hpp"

namespace arcade
{
    class SfmlBase : public IDisplayModule {
        public:
            SfmlBase();
            ~SfmlBase();

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
            sf::RenderWindow _window;
            sf::Event _event;
            std::vector<sf::Text> _text;
            sf::Font _font;

            std::vector<sf::Sprite> _sprite;

            std::string _path;
            std::string _gamesCommand;

            int _username;
            int _game;
            int _gameLaunch;
            int _head;

            MyStruct::_textToDraw _textDisplay;

        private:
    };
}

#endif /* !SFMLBASEHEADER */
