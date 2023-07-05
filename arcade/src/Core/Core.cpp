/*
** EPITECH PROJECT, 2023
** Object-Oriented Programming |-| Arcade
** File description:
** Core cpp
*/

#include "Core.hpp"

namespace arcade
{
    Core::Core(std::string filename)
    {
        this->_state = 0;
        this->_gameStart = 0;
        this->_graphics = filename;
        this->_symbol = RTLD_LAZY;
        this->_lib = arcade::MyDlLib();
        this->_games = "lib/arcade_home.so";

        this->SetAllVector();
        this->OpenLib();
    }

    Core::~Core()
    {
        for (int i = 0; i < this->_allHandle.size(); i++) {
            this->_lib.MyDlClose(this->_allHandle[i]);
        }
    }

    void Core::DlOpenCallGraphics(std::string path)
    {
        this->_handle = this->_lib.MyDlOpen(path.c_str(), this->_symbol);
        this->_function = (IDisplayModule *(*)(void))this->_lib.MyDlSym(this->_handle, "InitLibrary");
        this->_libGraphics.push_back(this->_function());
        this->_allHandle.push_back(this->_handle);
    }

    void Core::DlOpenCallGames(std::string path)
    {
        this->_handle = this->_lib.MyDlOpen(path.c_str(), this->_symbol);
        this->_functionG = (IGameModule *(*)(void))this->_lib.MyDlSym(this->_handle, "InitGames");
        this->_libGames.push_back(this->_functionG());
        this->_allHandle.push_back(this->_handle);
    }

    void Core::SetAllVector()
    {
        this->_allLibs.push_back("lib/arcade_ncurses.so");
        this->_allLibs.push_back("lib/arcade_sdl2.so");
        this->_allLibs.push_back("lib/arcade_sfml.so");

        this->_allGames.push_back("lib/arcade_home.so");
        this->_allGames.push_back("lib/arcade_snake.so");
        this->_allGames.push_back("lib/arcade_nibbler.so");

        for (int i = 0; i < this->_allLibs.size(); i++) {
            this->DlOpenCallGraphics(this->_allLibs[i]);
        }
        for (int i = 0; i < this->_allGames.size(); i++) {
            this->DlOpenCallGames(this->_allGames[i]);
        }
    }

    void Core::FindGraphics()
    {
        for (int i = 0; i < this->_allLibs.size(); i++)
        {
            if (this->_allLibs[i] == this->_graphics) {
                this->_module = this->_libGraphics[i];
                break;
            }
        }
    }

    void Core::FindGames()
    {
        for (int i = 0; i < this->_allGames.size(); i++)
        {
            if (this->_allGames[i] == this->_games) {
                this->_moduleG = this->_libGames[i];
                break;
            }
        }
    }

    void Core::LoadGamesThings()
    {
        this->_text.x = this->_moduleG->GetCoords().first;
        this->_text.y = this->_moduleG->GetCoords().second;
        this->_text.text = this->_moduleG->GetText();
        this->_text.sprites = this->_moduleG->GetSprites();
        this->_text.map = this->_moduleG->GetMap();
        this->_text.leaderboard = this->_moduleG->GetLeaderboard();
        this->_text.xSprite = this->_moduleG->GetCoordsSprites().first;
        this->_text.ySprite = this->_moduleG->GetCoordsSprites().second;
        this->_text.username = this->_moduleG->GetPlayer();
        this->_text.SetInput = [&](int c) { this->_moduleG->SetInput(c);};
        this->_text.death = this->_moduleG->GetDeath();

        this->_module->LoadStruct(this->_text);
    }

    void Core::OpenLib()
    {
        while (1) {
            this->FindGraphics();
            this->FindGames();
            this->LoopGraphical();

            if (this->_graphics == "Exit") {
                break;
            }
        }
    }

    void Core::LoopGraphical()
    {
        if (this->_state == 0) {
            this->_module->Init();
            this->_state = 1;
        }
        while (1) {
            this->LoadGamesThings();
            if (this->_gameStart == 0) {
                this->_module->DisplayHome();
            } else if (this->_gameStart != 0) {
                this->GameProcess();
            }
            this->_graphics = this->_module->Command();
            if (this->CommandCheck() == 1) {
                break;
            }
        }
    }

    void Core::GameProcess()
    {
        this->_module->DisplayMap();
        this->_moduleG->GameProgress();
        this->_module->DisplayOther(this->_moduleG->GetScore());
    }

    int Core::CommandCheck()
    {
        if (this->_graphics == "PLAY") {
            this->_gameStart = 1;
            return (0);
        } else if (this->_graphics != "") {
            this->_module->QuitArcade();
            this->_state = 0;
            return (1);
        }
        this->_games = this->_module->GamesCommand();
        if (this->_games != "") {
            this->_gameStart = 0;
            return (1);
        }
        this->_user = this->_module->SetUsername();
        if (this->_user != 0) {
            this->Username();
        }
        return (0);
    }

    void Core::Username()
    {
        if (this->_user != 0 && this->_user != 0407 && this->_moduleG->GetPlayer().size() < 9) {
            char user = this->_user;
            this->_moduleG->SetPlayer(this->_moduleG->GetPlayer() + user);
        } else if (this->_user == 0407 && this->_moduleG->GetPlayer().size() > 1) {
            this->_moduleG->SetPlayer(this->_moduleG->GetPlayer().erase(this->_moduleG->GetPlayer().size() - 1));
        }
        this->_username = this->_moduleG->GetPlayer();
    }
}
