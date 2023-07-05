/*
** EPITECH PROJECT, 2023
** Object-Oriented Programming |-| Arcade
** File description:
** SfmlBase cpp
*/

#include "SfmlBase.hpp"

namespace arcade
{
    SfmlBase::SfmlBase()
    {
        this->_head = 0;
        this->_gameLaunch = 0;
        this->_username = 0;
        this->_gamesCommand = "";
        this->_path = "src/Graphics/Sprites/";
        this->_font.loadFromFile(this->_path + "arial.ttf");
    }

    SfmlBase::~SfmlBase()
    {
    }

    void SfmlBase::Init()
    {
        this->_window.create(sf::VideoMode(1920, 1080), "SFML Window");
    }

    void SfmlBase::LoadStruct(MyStruct::_textToDraw textDisplay)
    {
        this->_window.clear();
        this->_textDisplay = textDisplay;

        if (this->_gameLaunch != 1) {
            this->InitColor();
        }
        this->_window.clear();
        sf::Text text;

        text.setPosition(0 * 12 + 8, 13 * 24);
        text.setString(this->_textDisplay.username);
        text.setFont(this->_font);
        text.setCharacterSize(22);
        text.setFillColor(sf::Color::White);
        this->_text.push_back(text);
    }

    void SfmlBase::InitColor()
    {
        sf::Text text;
        sf::Texture t;
        sf::Sprite s;

        for (std::size_t i = 0; i < this->_textDisplay.text.size(); i++) {
            text.setPosition(this->_textDisplay.x[i] * 12 + 8, this->_textDisplay.y[i] * 24);
            text.setString(this->_textDisplay.text[i]);
            text.setFont(this->_font);
            text.setCharacterSize(22);
            text.setFillColor(sf::Color::White);
            this->_text.push_back(text);
        }
        for (std::size_t i = 0; i < this->_textDisplay.sprites.size(); i++) {
            t.loadFromFile(this->_textDisplay.sprites[i]);
            s.setTexture(t);
            s.setOrigin(this->_textDisplay.xSprite[i], this->_textDisplay.ySprite[i]);
            s.setScale(
                (float) this->_window.getSize().x / s.getTexture()->getSize().x,
                (float) this->_window.getSize().y / s.getTexture()->getSize().y
            );
            this->_sprite.push_back(s);
            this->_window.draw(this->_sprite[i]);
        }
    }

    void SfmlBase::DisplayHome()
    {
        for (std::size_t i = 0; i < this->_text.size(); i++) {
            this->_window.draw(this->_text[i]);
        }
        this->_window.display();
    }

    void SfmlBase::DisplayParsing()
    {}

    void SfmlBase::DisplayMap()
    {
        this->_game = 1;
        this->_gameLaunch = 1;
        this->_window.clear();

        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("src/Graphics/Sprites/snake.png")) {
            std::cerr << "Failed to load background texture" << std::endl;
            return;
        }
        sf::Sprite backgroundSprite(backgroundTexture);
        backgroundSprite.setScale(
            (float)this->_window.getSize().x / backgroundSprite.getTexture()->getSize().x,
            (float)this->_window.getSize().y / backgroundSprite.getTexture()->getSize().y
        );
        this->_window.draw(backgroundSprite);

        sf::Texture backgroundSquare;
        if (!backgroundSquare.loadFromFile("src/Graphics/Sprites/carre.png")) {
            std::cerr << "Failed to load background texture" << std::endl;
            return;
        }
        sf::Sprite SpriteSquare(backgroundSquare);
        SpriteSquare.setScale(0.2f, 0.2f);
        SpriteSquare.setPosition(1160.f, 565.f);
        this->_window.draw(SpriteSquare);

        sf::Texture backgroundSquare2;
        if (!backgroundSquare2.loadFromFile("src/Graphics/Sprites/carre.png")) {
            std::cerr << "Failed to load background texture" << std::endl;
            return;
        }
        sf::Sprite SpriteSquare2(backgroundSquare2);
        SpriteSquare2.setScale(0.7f, 1.0f);
        SpriteSquare2.setPosition(1260.f, 65.f);
        this->_window.draw(SpriteSquare2);

        sf::Font font;
        if (!font.loadFromFile("src/Graphics/Sprites/arial.ttf")) {
            std::cerr << "Failed to load font" << std::endl;
            return;
        }

        sf::Text text("Commands :\n[^] : Move Forward\n[>] : Move Right\n[<] : Move Left\n[v] : Move Down\n[S] : Previous Library\n[D] : Next Library\n[Suppr] : Leave", font, 20);
        text.setFillColor(sf::Color::White);
        text.setPosition(300, 600);

        this->_window.draw(text);

        sf::Text text2;

        for (std::size_t i = 0; i < this->_textDisplay.leaderboard.size(); i++) {
            text2.setPosition(1360, 280 + (i * 20));
            text2.setString(this->_textDisplay.leaderboard[i]);
            text2.setFont(this->_font);
            text2.setCharacterSize(22);
            text2.setFillColor(sf::Color::White);
            this->_window.draw(text2);
        }

        int i1 = 0;
        for (std::size_t i = 0; i < this->_textDisplay.map.size(); i++) {
            for (int j = 0; this->_textDisplay.map[i][j] != ':'; j++) {
                if (this->_textDisplay.map[i][j] == '#') {
                    i1 = i;
                    sf::RectangleShape bodyPart(sf::Vector2f(25, 25));
                    bodyPart.setFillColor(sf::Color::White);
                    bodyPart.setPosition(sf::Vector2f((j + 70) * 12 + 8, (i1 + 5) * 28));
                    this->_window.draw(bodyPart);
                } else if (this->_textDisplay.map[i][j] != '#' && this->_textDisplay.map[i][j] != '.') {
                    i1 = i;
                    sf::RectangleShape bodyPart(sf::Vector2f(25, 25));
                    bodyPart.setFillColor(sf::Color::Blue);
                    bodyPart.setPosition(sf::Vector2f((j + 70) * 12 + 8, (i1 + 5) * 28));
                    this->_window.draw(bodyPart);
                }
            }
        }
    }

    void SfmlBase::DisplayPlayer(std::pair<std::vector<int>, std::vector<int>>)
    {}

    void SfmlBase::DisplayOther(int score)
    {

        sf::Text text;
        sf::Texture t;
        sf::Sprite s;

        text.setPosition(1200, 600);
        text.setString(std::to_string(score));
        text.setFont(this->_font);
        text.setCharacterSize(22);
        text.setFillColor(sf::Color::White);
        this->_window.draw(text);

        this->_window.display();
    }

    std::string SfmlBase::Command()
    {
        while (this->_window.pollEvent(this->_event))
        {
            if (this->_event.type == sf::Event::Closed) {
                return ("Exit");
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Delete)) {
                return ("Exit");
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::F5)) {
                return ("lib/arcade_ncurses.so");
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::F6)) {
                return ("lib/arcade_sdl2.so");
            }
            if (this->_game != 0 && this->_gameLaunch == 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                this->_gameLaunch = 1;
                this->_window.clear(sf::Color::White);
                return ("PLAY");
            }
            if (this->_game != 1 && sf::Keyboard::isKeyPressed(sf::Keyboard::F2)) {
                this->_window.clear(sf::Color::White);
                this->_game = 1;
                this->_gamesCommand = "lib/arcade_nibbler.so";
            }
            else if (this->_game != 2 && sf::Keyboard::isKeyPressed(sf::Keyboard::F4)) {
                this->_window.clear(sf::Color::White);
                this->_game = 2;
                this->_gamesCommand = "lib/arcade_snake.so";
            } else if (this->_game != 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Multiply)) {
                this->_game = 0;
                this->_gamesCommand = "lib/arcade_home.so";
            } else {
                this->_gamesCommand = "";
            }
            if (this->_event.type == sf::Event::TextEntered) {
                if ((this->_event.text.unicode >= 65 && this->_event.text.unicode <= 97) ||
                    (this->_event.text.unicode >= 97 && this->_event.text.unicode <= 122)) {
                    this->_username = this->_event.text.unicode;
                }
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
                this->_username = 0407;
                this->_window.clear();
            } else {
                this->_username = 0;
            }
            if (this->_game != 0 && this->_gameLaunch == 1 && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            this->_textDisplay.SetInput(0403);
            }
            if (this->_game != 0 && this->_gameLaunch == 1 && sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                this->_textDisplay.SetInput(0404);
            }
            if (this->_game != 0 && this->_gameLaunch == 1 && sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                this->_textDisplay.SetInput(0402);
            }
            if (this->_game != 0 && this->_gameLaunch == 1 && sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                this->_textDisplay.SetInput(0405);
            }
        }
        return ("");
    }

    std::string SfmlBase::GamesCommand()
    {
        return (this->_gamesCommand);
    }

    int SfmlBase::SetUsername()
    {
        return (this->_username);
    }

    void SfmlBase::QuitArcade()
    {
        this->_window.close();
    }
}

extern "C"
{
    arcade::IDisplayModule *InitLibrary()
    {
        static arcade::SfmlBase display;
        return &display;
    }
}
