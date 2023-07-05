/*
** EPITECH PROJECT, 2023
** Object-Oriented Programming |-| Arcade
** File description:
** Core hpp
*/

#ifndef COREHEADER
#define COREHEADER

#include "../Include.hpp"

namespace arcade
{
    class Core {
        public:
            Core(std::string filename);
            ~Core();

            void SetAllVector();
            void FindGraphics();
            void FindGames();
            void LoadGamesThings();

            void OpenLib();
            void DlOpenCallGraphics(std::string path);
            void DlOpenCallGames(std::string path);
            void LoopGraphical();
            void GameProcess();
            int CommandCheck();
            void Username();

        protected:
            std::vector<IDisplayModule *> _libGraphics;
            std::vector<IGameModule *> _libGames;
            std::vector<std::string> _allLibs;
            std::vector<std::string> _allGames;
            std::vector<void *> _allHandle;

            IDisplayModule *(*_function)();
            IGameModule *(*_functionG)();

            IDisplayModule *_module;
            IGameModule *_moduleG;

            MyDlLib _lib;

            std::string _graphics;
            std::string _games;
            std::string _username;

            int _symbol;
            int _state;
            int _user;
            int _gameStart;

            void *_handle;

            MyStruct::_textToDraw _text;

        private:
    };
}

#endif /* !COREHEADER */
