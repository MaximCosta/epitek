/*
** EPITECH PROJECT, 2023
** Object-Oriented Programming |-| Arcade
** File description:
** Home Getter for all Graphicals Library
*/

#ifndef HOMEHEADER
#define HOMEHEADER

#include "../IGameModule.hpp"

namespace arcade
{
    class Home : public IGameModule {
        public:
            Home();
            ~Home();

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

            std::string GetPlayer();

            // All Graphics:
            std::pair<std::vector<int>, std::vector<int>> GetCoords();
            std::pair<std::vector<int>, std::vector<int>> GetCoordsSprites();
            std::vector<std::string> GetText();
            std::vector<std::string> GetLeaderboard();
            std::vector<int> GetCommand();
            std::vector<std::string>  GetMap();
            void SetInput(int c);
            int GetScore();
            int GetDeath();

            // Sfml / Sdl2 Graphics:
            std::vector<std::string> GetSprites();

            // Ncurses Graphics:
            std::vector<int> GetColors();

        protected:
            std::pair<std::vector<int>, std::vector<int>> _coordsText;
            std::pair<std::vector<int>, std::vector<int>> _coordsSprite;

            std::vector<std::string> _textToDisplay;
            std::vector<std::string> _sprites;
            std::vector<std::string> _leaderboard;

            std::vector<int> _commands;
            std::vector<int> _colors;

            std::string _player;
            std::vector<std::string> _map;
            std::string _line;

            int _myScore;
            int _stateFile;
            int _input;

        private:
    };
}

#endif /* !HOMEHEADER */
