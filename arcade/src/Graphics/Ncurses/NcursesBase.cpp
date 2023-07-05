/*
** EPITECH PROJECT, 2023
** Object-Oriented Programming |-| Arcade
** File description:
** Ncurses cpp
*/

#include "NcursesBase.hpp"

namespace arcade
{
    NcursesBase::NcursesBase()
    {
        this->_gameLaunch = 0;
        this->_state = 0;
    }

    NcursesBase::~NcursesBase()
    {
    }

    void NcursesBase::Init()
    {
        initscr();
        noecho();
        keypad(stdscr, TRUE);
        nodelay(stdscr, TRUE);
        start_color();
        curs_set(0);
        init_color(COLOR_BLACK, 0, 0, 0);
        srand(time(NULL));
        clear();
        this->InitColor();
    }

    void NcursesBase::InitColor()
    {
        init_pair(1, COLOR_YELLOW, COLOR_BLACK);
        init_pair(2, COLOR_GREEN, COLOR_BLACK);
        init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
        init_pair(4, COLOR_BLUE, COLOR_BLACK);
        init_pair(5, COLOR_CYAN, COLOR_BLACK);
        init_pair(6, COLOR_RED, COLOR_BLACK);
        init_pair(7, COLOR_WHITE, COLOR_BLACK);
        init_pair(8, COLOR_WHITE, COLOR_WHITE);
    }

    void NcursesBase::LoadStruct(MyStruct::_textToDraw textDisplay)
    {
        this->_textDisplay = textDisplay;
        if (this->_state == 0) {
            clear();
            this->_state = 1;
        }
    }

    void NcursesBase::DisplayHome()
    {
        for (std::size_t i = 0; i < this->_textDisplay.x.size(); i++) {
            mvprintw(this->_textDisplay.y[i], this->_textDisplay.x[i], "%s",
                this->_textDisplay.text[i].c_str());
        }
        if (this->_game != 0) {
            for (std::size_t i = 0; i < this->_textDisplay.leaderboard.size();
                 i++) {
                mvprintw(15 + i, 123, "%s",
                    this->_textDisplay.leaderboard[i].c_str());
            }
        }
        if (this->_game != 0) {
            mvprintw(13, 0, "%s", this->_textDisplay.username.c_str());
        }
        refresh();
    }

    void NcursesBase::DisplayParsing()
    {
    }

    void NcursesBase::DisplayMap()
    {
        for (int i = 0; i < 19; i++) {
            mvaddch(12, 123 - 2 + i, ' ' | COLOR_PAIR(8));
            mvaddch(21, 123 - 2 + i, ' ' | COLOR_PAIR(8));
        }
        for (int i = 0; i < 10; i++) {
            mvaddch(12 + i, 121, ' ' | COLOR_PAIR(8));
            mvaddch(12 + i, 140, ' ' | COLOR_PAIR(8));
        }
        mvprintw(14, 123, "Leaderboard:");
        for (std::size_t i = 0; i < this->_textDisplay.leaderboard.size();
             i++) {
            mvprintw(
                15 + i, 123, "%s", this->_textDisplay.leaderboard[i].c_str());
        }
        if (this->_textDisplay.death == 1) {
            mvprintw(24, 123, "You died");
            mvprintw(25, 123, "Press [*] key to continue");
            refresh();
            getch();
        }
        this->_game = 1;
        this->_gameLaunch = 1;
        for (std::size_t i = 0; i < this->_textDisplay.map.size(); i++) {
            for (std::size_t j = 0; this->_textDisplay.map[i][j] != ':'; j++) {
                if (this->_textDisplay.map[i][j] == '#') {
                    mvaddch(i + 10, j + 65, ' ' | COLOR_PAIR(8));
                    refresh();
                } else if (this->_textDisplay.map[i][j] == '.') {
                    mvaddch(i + 10, j + 65, ' ');
                    refresh();
                } else {
                    mvaddch(i + 10, j + 65,
                        this->_textDisplay.map[i][j] | COLOR_PAIR(4));
                    refresh();
                }
            }
        }
    }

    void NcursesBase::DisplayPlayer(
        std::pair<std::vector<int>, std::vector<int>>)
    {
    }

    void NcursesBase::DisplayOther(int score)
    {
        attron(COLOR_PAIR(2));
        mvprintw(3, C / 2 - 5, "Snake My Name:");
        attroff(COLOR_PAIR(2));

        mvprintw(10, 12, "Player: %s", this->_textDisplay.username.c_str());
        attron(COLOR_PAIR(1));
        for (int i = 0; i < 15; i++) {
            mvaddch(37, C / 2 - 7 + i, ' ' | COLOR_PAIR(8));
            mvaddch(42, C / 2 - 7 + i, ' ' | COLOR_PAIR(8));
        }
        for (int i = 0; i < 5; i++) {
            mvaddch(37 + i, C / 2 - 7, ' ' | COLOR_PAIR(8));
            mvaddch(37 + i, C / 2 + 7, ' ' | COLOR_PAIR(8));
        }
        mvprintw(39, C / 2 - 5, "Your Score:");
        mvprintw(40, C / 2, "%d", score);
        attroff(COLOR_PAIR(1));
        attron(COLOR_PAIR(4));
        mvprintw(30, 12, "Commands:");
        mvprintw(32, 6, "[^] : Move Forward");
        mvprintw(33, 6, "[>] : Move Right");
        mvprintw(34, 6, "[<] : Move Left");
        mvprintw(35, 6, "[v] : Move Down");

        mvprintw(37, 6, "[S] : Previous Library");
        mvprintw(38, 6, "[D] : Next Library");

        mvprintw(40, 6, "[Suppr] : Leave");
        attroff(COLOR_PAIR(4));
    }

    std::string NcursesBase::Command()
    {
        this->_c = getch();

        if (this->_c == KEY_DC) {
            return ("Exit");
        } else if (this->_c == KEY_F(6)) {
            return ("lib/arcade_sfml.so");
        } else if (this->_c == KEY_F(5)) {
            return ("lib/arcade_sdl2.so");
        }
        if (this->_game != 0 && this->_gameLaunch != 1 && this->_c == KEY_UP) {
            clear();
            this->_gameLaunch = 1;
            return ("PLAY");
        }
        if (this->_game != 0 && this->_gameLaunch == 1) {
            this->_textDisplay.SetInput(this->_c);
        }
        return ("");
    }

    std::string NcursesBase::GamesCommand()
    {
        if (this->_game != 1 && this->_c == KEY_F(2)) {
            this->_state = 0;
            this->_game = 1;
            return ("lib/arcade_nibbler.so");
        } else if (this->_game != 2 && this->_c == KEY_F(4)) {
            this->_state = 0;
            this->_game = 2;
            return ("lib/arcade_snake.so");
        } else if (this->_game != 0 && this->_c == '*') {
            this->_gameLaunch = 0;
            this->_state = 0;
            this->_game = 0;
            return ("lib/arcade_home.so");
        }
        return ("");
    }

    int NcursesBase::SetUsername()
    {
        if ((this->_game != 0)
            && ((this->_c >= 65 && this->_c <= 90)
                || (this->_c >= 97 && this->_c <= 122))) {
            return (this->_c);
        }
        if (this->_c == KEY_BACKSPACE) {
            clear();
            return (this->_c);
        }
        return (0);
    }

    void NcursesBase::QuitArcade()
    {
        clear();
        endwin();
        attroff(COLOR_PAIR(1));
        attroff(COLOR_PAIR(2));
        attroff(COLOR_PAIR(3));
        attroff(COLOR_PAIR(4));
        attroff(COLOR_PAIR(5));
        attroff(COLOR_PAIR(6));
        attroff(COLOR_PAIR(7));
    }
} // namespace arcade

extern "C"
{
    arcade::IDisplayModule *InitLibrary()
    {
        static arcade::NcursesBase display;
        return &display;
    }
}
