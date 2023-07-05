/*
** EPITECH PROJECT, 2023
**  Object-Oriented Programming |-| Arcade
** File description:
** NibblerBase hpp
*/

#ifndef NibblerBaseHEADER
#define NibblerBaseHEADER

#include "../IGameModule.hpp"

namespace arcade
{
    class NibblerBase : public IGameModule {
        public:
            NibblerBase();
            ~NibblerBase();

            void LoadEverything();
            void CheckFlagsParsing();
            void DeathThingsToDo();

            // Games:
            void Timer();
            void GameProgress();
            void GameRules();
            void GameParticularity();
            void SetCommand();
            void SetPlayer(std::string player);
            void DisplayPlayer(std::vector<std::string> *map);
            void DisplayFood(std::vector<std::string> *map);
            void SetInput(int c);
            int CheckCollision(int x, int y);
            std::string GetPlayer();

            // All Graphics:
            std::pair<std::vector<int>, std::vector<int>> GetCoords();
            std::pair<std::vector<int>, std::vector<int>> GetCoordsSprites();
            std::vector<std::string> GetText();
            std::vector<std::string> GetLeaderboard();
            std::vector<int> GetCommand();
            std::vector<std::string> GetMap();
            int GetScore();
            int GetDeath();

            // Sfml / Sdl2 Graphics:
            std::vector<std::string> GetSprites();

            // Ncurses Graphics:
            std::vector<int> GetColors();

        protected:
            std::pair<std::vector<int>, std::vector<int>> _coordsText;
            std::pair<std::vector<int>, std::vector<int>> _coordsSprite;
            std::pair<std::vector<int>, std::vector<int>> _snake;

            std::pair<int, int> _food;
            std::vector<std::pair<std::string, int>> _players;

            std::vector<std::string> _textToDisplay;
            std::vector<std::string> _sprites;
            std::vector<std::string> _leaderboard;
            std::vector<std::string> _map;

            std::vector<int> _commands;
            std::vector<int> _colors;

            std::string _player;
            std::string _line;
            std::string _head;
            std::string _body;

            char _charFood;

            int _snakeDirection;
            int _timer;
            int _myScore;
            int _stateFile;
            int _input;
            int _death;
            int _lead;

        private:
    };
}

#endif /* !NibblerBaseHEADER */
