/*
** EPITECH PROJECT, 2023
** Object-Oriented Programming |-| Arcade
** File description:
** Home Getter for all Graphicals Lib
*/

#include "Home.hpp"

namespace arcade
{
    Home::Home()
    {
        this->_player = " ";
        this->_stateFile = 0;
        std::ifstream file("src/Games/Home/home.txt");

        if (file.is_open()) {
            while (std::getline(file, this->_line)) {
                this->LoadEverything();
            }
        }
        file.close();
    }

    Home::~Home()
    {}

    void Home::LoadEverything()
    {
        this->CheckFlagsParsing();
        if (this->_stateFile == 1 && this->_line[0] != '.') {
            this->_coordsText.first.push_back(
                std::stoi(this->_line.substr(0, this->_line.find(" "))));
            this->_coordsText.second.push_back(
                std::stoi(this->_line.substr(this->_line.find(" ") + 1)));
        }
        if (this->_stateFile == 2 && this->_line[0] != '.') {
            this->_textToDisplay.push_back(this->_line);
        }
        if (this->_stateFile == 3 && this->_line[0] != '.') {
            this->_sprites.push_back(this->_line);
        }
        if (this->_stateFile == 4 && this->_line[0] != '.') {
            this->_coordsSprite.first.push_back(
                std::stoi(this->_line.substr(0, this->_line.find(" "))));
            this->_coordsSprite.second.push_back(
                std::stoi(this->_line.substr(this->_line.find(" ") + 1)));
        }
    }

    void Home::CheckFlagsParsing()
    {
        if (this->_line == ".coordsText") {
            this->_stateFile = 1;
        }
        if (this->_line == ".text") {
            this->_stateFile = 2;
        }
        if (this->_line == ".sprite") {
            this->_stateFile = 3;
        }
        if (this->_line == ".coordsSprite") {
            this->_stateFile = 4;
        }
    }

    void Home::DeathThingsToDo()
    {}

    void Home::Timer()
    {}

    void Home::GameProgress()
    {}

    void Home::GameRules()
    {}

    void Home::GameParticularity()
    {}

    void Home::SetCommand()
    {}

    void Home::SetInput(int input)
    {
        this->_input = input;
    }

    void Home::SetPlayer(std::string player)
    {
        this->_player = player;
    }

    std::string Home::GetPlayer()
    {
        return (this->_player);
    }

    std::pair<std::vector<int>, std::vector<int>> Home::GetCoords()
    {
        return (this->_coordsText);
    }

    std::pair<std::vector<int>, std::vector<int>> Home::GetCoordsSprites()
    {
        return (this->_coordsSprite);
    }

    std::vector<std::string> Home::GetText()
    {
        return (this->_textToDisplay);
    }

    std::vector<std::string> Home::GetLeaderboard()
    {
        return (this->_leaderboard);
    }

    std::vector<int> Home::GetCommand()
    {
        return (this->_commands);
    }

    std::vector<std::string> Home::GetMap()
    {
        return (this->_map);
    }

    int Home::GetScore()
    {
        return (this->_myScore);
    }

    std::vector<std::string> Home::GetSprites()
    {
        return (this->_sprites);
    }

    std::vector<int> Home::GetColors()
    {
        return (this->_colors);
    }

    int Home::GetDeath()
    {
        return (0);
    }
}

extern "C"
{
    arcade::IGameModule *InitGames()
    {
        static arcade::Home display;
        return &display;
    }
}
