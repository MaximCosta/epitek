/*
** EPITECH PROJECT, 2023
** Object-Oriented Programming |-| Arcade
** File description:
** Interface Games
*/

#ifndef IGAMEMODULEHEADER
#define IGAMEMODULEHEADER

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
#include <fstream>
#include <chrono>
#include <memory>
#include <random>
#include <regex>
#include <thread>
#include <algorithm>

namespace arcade
{
    class IGameModule {
        public:
            virtual ~IGameModule() = default;

            virtual void LoadEverything() = 0;
            virtual void CheckFlagsParsing() = 0;

            // Games:
            virtual void Timer() = 0;
            virtual void GameProgress() = 0;
            virtual void GameRules() = 0;
            virtual void GameParticularity() = 0;
            virtual void SetCommand() = 0;
            virtual void SetPlayer(std::string player) = 0;
            virtual void DeathThingsToDo() = 0;

            virtual std::string GetPlayer() = 0;

            // All Graphics:
            virtual std::pair<std::vector<int>, std::vector<int>> GetCoords() = 0;
            virtual std::pair<std::vector<int>, std::vector<int>> GetCoordsSprites() = 0;
            virtual std::vector<std::string> GetText() = 0;
            virtual std::vector<std::string> GetLeaderboard() = 0;
            virtual std::vector<int> GetCommand() = 0;
            virtual std::vector<std::string> GetMap() = 0;
            virtual void SetInput(int c) = 0;
            virtual int GetScore() = 0;
            virtual int GetDeath() = 0;

            // Sfml / Sdl2 Graphics:
            virtual std::vector<std::string> GetSprites() = 0;

            // Ncurses Graphics:
            virtual std::vector<int> GetColors() = 0;

        protected:
        private:
    };
}

#endif /* !IGAMEMODULEHEADER */
