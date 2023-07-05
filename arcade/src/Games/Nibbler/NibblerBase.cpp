/*
** EPITECH PROJECT, 2023
**  Object-Oriented Programming |-| Arcade
** File description:
** NibblerBase cpp
*/

#include "NibblerBase.hpp"

namespace arcade
{
    NibblerBase::NibblerBase()
    {
        this->_lead = 0;
        this->_player = " ";
        this->_stateFile = 0;
        std::ifstream file("src/Games/Nibbler/nibbler.txt");
        std::ifstream file2("Leaderboard/lead_snake.txt");

        if (file.is_open()) {
            while (std::getline(file, this->_line)) {
                this->LoadEverything();
            }
        }
        file.close();
        if (file2.is_open()) {
            while (std::getline(file2, this->_line)) {
                this->_leaderboard.push_back(this->_line);
            }
        }

        std::ifstream fileMap("src/Games/Nibbler/maps.txt");
        if (fileMap.is_open())
            while (std::getline(fileMap, this->_line))
                this->_map.push_back(this->_line);
        fileMap.close();

        this->_snakeDirection = 1;
        this->_head = "<^>v";
        this->_body = "ratio-kylian-se-golem-c-est-la-blague-du-quoi-feur-tu-"
                      "connaissais-pas";
        this->_charFood = 'o';
        this->_food.first = 2;
        this->_food.second = 2;
        this->_input = 0;

        this->_snake.first.push_back(2);
        this->_snake.second.push_back(12);
        for (int i = 1; i < 4; i++) {
            this->_snake.first.push_back(this->_snake.first[0]);
            this->_snake.second.push_back(this->_snake.second[0] + i);
        }
    }

    NibblerBase::~NibblerBase()
    {
    }

    void NibblerBase::LoadEverything()
    {
        std::regex regex_text(
            "(\\d+)\\s+(\\d+)\\s+text\\s+\\((\\d+),(\\d+),(\\d+)\\)\\s+(.*)");
        std::regex regex_sprite("(\\d+)\\s+(\\d+)\\s+sprite\\s+src\\/"
                                "Graphics\\/Sprites\\/(\\w+\\.\\w+)");

        std::smatch match_text;
        if (std::regex_match(this->_line, match_text, regex_text)) {
            this->_coordsText.first.push_back(stoi(match_text[1]));
            this->_coordsText.second.push_back(stoi(match_text[2]));
            this->_textToDisplay.push_back(match_text[6]);
        }

        std::smatch match_sprite;
        if (std::regex_match(this->_line, match_sprite, regex_sprite)) {
            this->_coordsSprite.first.push_back(stoi(match_sprite[1]));
            this->_coordsSprite.second.push_back(stoi(match_sprite[2]));
            this->_sprites.push_back(match_sprite[3]);
        }
    }

    void NibblerBase::CheckFlagsParsing()
    {}

    void NibblerBase::DeathThingsToDo()
    {
        std::ifstream file("Leaderboard/lead_nibbler.txt");

        std::string line;

        while (std::getline(file, line)) {
            this->_players.push_back(std::make_pair(line.substr(0, line.find("->")), std::stoi(line.substr(line.find("->") + 2))));
        }
        file.close();

        this->_players.push_back(std::make_pair(this->_player, this->_myScore));

        std::sort(this->_players.begin(), this->_players.end(),
              [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
                  return a.second > b.second;
              });

        if (this->_players.size() > 5) {
            this->_players.pop_back();
        }

        std::ofstream outFile("Leaderboard/lead_nibbler.txt");

        if (outFile.is_open()) {
            for (std::size_t i = 0; i < this->_players.size(); i++) {
                outFile << this->_players[i].first << " -> " << this->_players[i].second << std::endl;
            }
        }
        outFile.close();
        this->_lead = 1;
    }

    void NibblerBase::Timer()
    {}

    void NibblerBase::GameProgress()
    {
        this->GameRules();
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
    }

    int NibblerBase::CheckCollision(int x1, int y1)
    {
        int x = this->_snake.first[0] + x1;
        int y = this->_snake.second[0] + y1;

        if (this->_map[y][x] == '#')
            return 1;
        for (int i = 0; i < (int) this->_snake.first.size(); i++) {
            if (this->_snake.first[i] == x && this->_snake.second[i] == y)
                return 1;
        }
        return 0;
    }

    void NibblerBase::GameRules()
    {
        int valid = 0;

        switch (this->_snakeDirection) {
            case 0:
                if (this->CheckCollision(-1, 0))
                    break;
                this->_snake.first.insert(
                    this->_snake.first.begin(), this->_snake.first[0] - 1);
                this->_snake.second.insert(
                    this->_snake.second.begin(), this->_snake.second[0]);
                valid = 1;
                break;
            case 1:
                if (this->CheckCollision(0, -1))
                    break;
                this->_snake.first.insert(
                    this->_snake.first.begin(), this->_snake.first[0]);
                this->_snake.second.insert(
                    this->_snake.second.begin(), this->_snake.second[0] - 1);
                valid = 1;
                break;
            case 2:
                if (this->CheckCollision(1, 0))
                    break;
                this->_snake.first.insert(
                    this->_snake.first.begin(), this->_snake.first[0] + 1);
                this->_snake.second.insert(
                    this->_snake.second.begin(), this->_snake.second[0]);
                valid = 1;
                break;
            case 3:
                if (this->CheckCollision(0, 1))
                    break;
                this->_snake.first.insert(
                    this->_snake.first.begin(), this->_snake.first[0]);
                this->_snake.second.insert(
                    this->_snake.second.begin(), this->_snake.second[0] + 1);
                valid = 1;
                break;
        }
        if (valid == 1 && this->_snake.first[0] == this->_food.first
            && this->_snake.second[0] == this->_food.second) {
            this->_food.first = rand() % (this->_map[0].size() - 2) + 1;
            this->_food.second = rand() % (this->_map.size() - 2) + 1;
            this->_myScore += 10;
        } else if (valid == 1) {
            this->_snake.first.pop_back();
            this->_snake.second.pop_back();
        } else {
            this->_death = 1;
            if (this->_lead == 0) {
                this->DeathThingsToDo();
            }
        }
    }

    void NibblerBase::SetInput(int c)
    {
        this->_input = c;

        if (c == -1)
            return;
        if (c == 122 && this->_snakeDirection != 3)
            this->_snakeDirection = 1;
        else if (c == 113 && this->_snakeDirection != 2)
            this->_snakeDirection = 0;
        else if (c == 115 && this->_snakeDirection != 1)
            this->_snakeDirection = 3;
        else if (c == 100 && this->_snakeDirection != 0)
            this->_snakeDirection = 2;
    }

    void NibblerBase::GameParticularity()
    {}

    void NibblerBase::SetCommand()
    {}

    void NibblerBase::DisplayPlayer(std::vector<std::string> *map)
    {
        (*map)[this->_snake.second[0]][this->_snake.first[0]] =
            this->_head[this->_snakeDirection];
        for (int i = 1; i < (int) this->_snake.first.size(); i++) {
            (*map)[this->_snake.second[i]][this->_snake.first[i]] =
                this->_body[(i - 1) % this->_body.size()];
        }
    }

    void NibblerBase::DisplayFood(std::vector<std::string> *map)
    {
        (*map)[this->_food.second][this->_food.first] = this->_charFood;
    }

    void NibblerBase::SetPlayer(std::string player)
    {
        this->_player = player;
    }

    std::string NibblerBase::GetPlayer()
    {
        return (this->_player);
    }

    std::pair<std::vector<int>, std::vector<int>> NibblerBase::GetCoords()
    {
        return (this->_coordsText);
    }

    std::pair<std::vector<int>, std::vector<int>> NibblerBase::GetCoordsSprites()
    {
        return (this->_coordsSprite);
    }

    std::vector<std::string> NibblerBase::GetText()
    {
        return (this->_textToDisplay);
    }

    std::vector<std::string> NibblerBase::GetLeaderboard()
    {
        return (this->_leaderboard);
    }

    std::vector<int> NibblerBase::GetCommand()
    {
        return (this->_commands);
    }

    std::vector<std::string> NibblerBase::GetMap()
    {
        std::vector<std::string> map;

        for (int i = 0; i < (int) this->_map.size(); i++) {
            map.push_back(this->_map[i]);
        }

        this->DisplayPlayer(&map);
        this->DisplayFood(&map);
        return (map);
    }

    int NibblerBase::GetScore()
    {
        return (this->_myScore);
    }

    std::vector<std::string> NibblerBase::GetSprites()
    {
        return (this->_sprites);
    }

    std::vector<int> NibblerBase::GetColors()
    {
        return (this->_colors);
    }

    int NibblerBase::GetDeath()
    {
        return (this->_death);
    }
}

extern "C"
{
    arcade::IGameModule *InitGames()
    {
        static arcade::NibblerBase display;
        return &display;
    }
}
