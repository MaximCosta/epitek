/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/
#include "../../../include/engine/Engine.hpp"
#include "../../../include/game/Game.hpp"
#include <iostream>
#include <cstring>

static const std::string IMAGE_BACKGROUND_PATH = "./bonus/resources/MainSceneBackground.png";
static const std::string IMAGE_BACKGROUND_2_PATH = "./bonus/resources/MainSceneBackground2.jpg";
static const std::string IMAGE_BACKGROUND_GIF_PATH = "./bonus/resources/MainSceneLogo.png";
static const std::string TEXT_FONT_PATH = "./bonus/resources/toto.ttf";
static const std::string MAIN_GUI = "./bonus/resources/MainGui.png";
static const std::string CURSOR = "./bonus/resources/Cursor.png";
static const std::string PLAY = "./bonus/resources/Play.png";
static const std::string QUIT = "./bonus/resources/Quit.png";
static const std::string HOW_TO_PLAY = "./bonus/resources/HowToPlay.png";
//static const std::string FONT_PATH = "./bonus/resources/times.ttf";


float iani = 0;
bool quit_full = false;
bool play_full = false;
bool Htp_full = false;

void cg::MainScene::onInit(sf::RenderWindow &window) {
    std::shared_ptr <cg::SpriteComponent> imageBackground = std::make_shared<cg::SpriteComponent>(
        cg::SpriteComponent("image_background_tag", IMAGE_BACKGROUND_PATH));

    imageBackground->setPosition(sf::Vector2f(0, 0));
    std::shared_ptr <cg::SpriteComponent> imageBackground2 = std::make_shared<cg::SpriteComponent>(
        cg::SpriteComponent("image_background2_tag", IMAGE_BACKGROUND_2_PATH));
    imageBackground2->setOrigin(sf::Vector2f(960, 540));
    imageBackground2->setPosition(sf::Vector2f(960, 540));
    imageBackground2->setScale(sf::Vector2f(0.998, 0.994));

    std::shared_ptr <cg::SpriteComponent> component = std::make_shared<cg::SpriteComponent>(
        cg::SpriteComponent("image_gif", IMAGE_BACKGROUND_GIF_PATH));
    component->setOrigin(sf::Vector2f(320, 180));
    component->setPosition(sf::Vector2f(960, 540));
    component->setScale(sf::Vector2f(2, 2));
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 12 && j == 4)
                break;
            component->addRect(sf::IntRect(j * 640, i * 360, 640, 360));
        }
    }

    // ADD MainGUI
    std::shared_ptr <cg::SpriteComponent> mainGui = std::make_shared<cg::SpriteComponent>(
        cg::SpriteComponent("MainGui", MAIN_GUI));
    mainGui->setPosition(sf::Vector2f(150, 100));
    mainGui->setVisible(false);

    // ADD Cursor
    std::shared_ptr <cg::SpriteComponent> cursor = std::make_shared<cg::SpriteComponent>(
        cg::SpriteComponent("Cursor", CURSOR));
    cursor->setTextureRect(sf::IntRect(0, 0, 22, 31));

    std::shared_ptr <cg::SpriteComponent> play = std::make_shared<cg::SpriteComponent>(
        cg::SpriteComponent("Play", PLAY));
    play->setTextureRect(sf::IntRect(550, 0, 0, 76));
    play->setVisible(false);
    play->setPosition(sf::Vector2f(155, 204));

    std::shared_ptr <cg::SpriteComponent> play_c = std::make_shared<cg::SpriteComponent>(
        cg::SpriteComponent("Play_c", PLAY));
    play_c->setTextureRect(sf::IntRect(550, 0, 550, 76));
    play_c->setVisible(false);
    play_c->setPosition(sf::Vector2f(155, 204));

    std::shared_ptr <cg::SpriteComponent> quit = std::make_shared<cg::SpriteComponent>(
        cg::SpriteComponent("Quit", QUIT));
    quit->setTextureRect(sf::IntRect(550, 0, 0, 76));
    quit->setVisible(false);
    quit->setPosition(sf::Vector2f(155, 356));

    std::shared_ptr <cg::SpriteComponent> quit_c = std::make_shared<cg::SpriteComponent>(
        cg::SpriteComponent("Quit_c", QUIT));
    quit_c->setTextureRect(sf::IntRect(550, 0, 550, 76));
    quit_c->setVisible(false);
    quit_c->setPosition(sf::Vector2f(155, 356));

    std::shared_ptr <cg::SpriteComponent> htp = std::make_shared<cg::SpriteComponent>(
        cg::SpriteComponent("Htp", HOW_TO_PLAY));
    htp->setTextureRect(sf::IntRect(550, 0, 0, 76));
    htp->setVisible(false);
    htp->setPosition(sf::Vector2f(155, 280));

    std::shared_ptr <cg::SpriteComponent> htp_c = std::make_shared<cg::SpriteComponent>(
        cg::SpriteComponent("Htp_c", HOW_TO_PLAY));
    htp_c->setTextureRect(sf::IntRect(550, 0, 550, 76));
    htp_c->setVisible(false);
    htp_c->setPosition(sf::Vector2f(155, 280));



    this->addComponent(imageBackground);
    this->addComponent(imageBackground2);
    this->addComponent(component);
    this->addComponent(mainGui);
    this->addComponent(play);
    this->addComponent(play_c);
    this->addComponent(quit);
    this->addComponent(quit_c);
    this->addComponent(htp);
    this->addComponent(htp_c);
    this->addComponent(cursor);
}

int cg::MainScene::onUpdate(sf::RenderWindow &window) {
    std::shared_ptr <cg::SpriteComponent> background_gif =
        std::dynamic_pointer_cast<cg::SpriteComponent>(
            this->getComponentFromTag("image_gif"));

    // GET Main_Gui
    std::shared_ptr <cg::SpriteComponent> mainGui =
        std::dynamic_pointer_cast<cg::SpriteComponent>(
            this->getComponentFromTag("MainGui"));
    // GET cursor
    std::shared_ptr <cg::SpriteComponent> cursor =
        std::dynamic_pointer_cast<cg::SpriteComponent>(
            this->getComponentFromTag("Cursor"));


    // UPDATE CURSOR
    cursor->setPosition(sf::Vector2f(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y));
    cursor->setTextureRect(sf::IntRect(0, 0, 22, 31));

    // GET PLAY BUTTON
    std::shared_ptr <cg::SpriteComponent> play =
        std::dynamic_pointer_cast<cg::SpriteComponent>(
            this->getComponentFromTag("Play"));
    std::shared_ptr <cg::SpriteComponent> play_c =
        std::dynamic_pointer_cast<cg::SpriteComponent>(
            this->getComponentFromTag("Play_c"));

    // GET QUIT BUTTON
    std::shared_ptr <cg::SpriteComponent> quit =
        std::dynamic_pointer_cast<cg::SpriteComponent>(
            this->getComponentFromTag("Quit"));
    std::shared_ptr <cg::SpriteComponent> quit_c =
        std::dynamic_pointer_cast<cg::SpriteComponent>(
            this->getComponentFromTag("Quit_c"));

    // GET HTP BUTTON
    std::shared_ptr <cg::SpriteComponent> htp =
        std::dynamic_pointer_cast<cg::SpriteComponent>(
            this->getComponentFromTag("Htp"));
    std::shared_ptr <cg::SpriteComponent> htp_c =
        std::dynamic_pointer_cast<cg::SpriteComponent>(
            this->getComponentFromTag("Htp_c"));

    static bool completeTextAnimation = false;
    if (background_gif) {
        iani += this->getDt();
        if (iani > 0.1) {
            background_gif->nextRect();
            sf::Color color = background_gif->getColor();
            background_gif->setColor(
                sf::Color(color.r, color.g, color.b, color.a - 5));
            if (background_gif->getColor().a == 0)
                this->removeComponent("image_gif");
            iani = 0;
        }
    } else {
        iani += this->getDt();
        if (iani > 1 && !this->getComponentFromTag("corewar_text")) {
            std::shared_ptr <cg::TextComponent> component = std::make_shared<cg::TextComponent>(
                cg::TextComponent("corewar_text", "C|", TEXT_FONT_PATH));
            component->setCharacterSize(115);
            component->setPosition(sf::Vector2f(1300, 540));
            component->setFillColor(sf::Color(0, 204, 102, 255));
            component->setOrigin(
                sf::Vector2f(component->getLocalBounds().width / 2,
                             component->getLocalBounds().height / 2));
            this->addComponent(component);
            iani = 0;
        } else if (this->getComponentFromTag("corewar_text")) {
            std::shared_ptr <cg::TextComponent> component =
                std::dynamic_pointer_cast<cg::TextComponent>(
                    this->getComponentFromTag("corewar_text"));
            if (!completeTextAnimation && iani > 0.3f &&
                strlen(component->getString().c_str()) != 8) {
                if (component->getString() == "C|")
                    component->setString("Co|");
                else if (component->getString() == "Co|")
                    component->setString("Cor|");
                else if (component->getString() == "Cor|")
                    component->setString("Core|");
                else if (component->getString() == "Core|")
                    component->setString("Corew|");
                else if (component->getString() == "Corew|")
                    component->setString("Corewa|");
                else if (component->getString() == "Corewa|") {
                    component->setString("Corewar|");
                    completeTextAnimation = true;
                    mainGui->setVisible(true);
                    play->setVisible(true);
                    quit->setVisible(true);
                    htp->setVisible(true);
                }
                iani = 0;
                component->setOrigin(
                    sf::Vector2f(component->getLocalBounds().width / 2,
                                 component->getLocalBounds().height / 2));
            } else if (strlen(component->getString().c_str()) == 8 &&
                       iani > 0.82f) {
                component->setString("Corewar");
                iani = 0;
            } else if (strlen(component->getString().c_str()) == 7 &&
                       iani > 0.82f) {
                component->setString("Corewar|");
                iani = 0;
            }
        }
    }

    // BUTTON PLAY UPDATE
    sf::IntRect rect = play->getTextureRect();
    if (isComponentHovered(play_c)) {
        cursor->setTextureRect(sf::IntRect(22, 0, 22, 31));
        if (rect.width < 550) {
            play_full = false;
            float speed = (2 * this->getDt()) * ((550 - rect.width) + 100);
            play->setTextureRect(sf::IntRect(rect.left, rect.top, rect.width + speed, rect.height));
        } else
            play_full = true;
    } else if (rect.width > 0) {
        play_full = false;
        float speed = (2 * this->getDt()) * (rect.width + 100);
        play->setTextureRect(sf::IntRect(rect.left, rect.top, rect.width - speed, rect.height));
    }

    // BUTTON QUIT UPDATE
    sf::IntRect Qrect = quit->getTextureRect();
    if (isComponentHovered(quit_c)) {
        cursor->setTextureRect(sf::IntRect(22, 0, 22, 31));
        if (Qrect.width < 550) {
            quit_full = false;
            float speed = (2 * this->getDt()) * ((550 - Qrect.width) + 100);
            quit->setTextureRect(sf::IntRect(Qrect.left, Qrect.top, Qrect.width + speed, Qrect.height));
        } else
            quit_full = true;
    } else if (Qrect.width > 0) {
        quit_full = false;
        float speed = (2 * this->getDt()) * (Qrect.width + 100);
        quit->setTextureRect(sf::IntRect(Qrect.left, Qrect.top, Qrect.width - speed, Qrect.height));
    }

    // BUTTON HTP UPDATE
    sf::IntRect Hrect = htp->getTextureRect();
    if (isComponentHovered(htp_c)) {
        cursor->setTextureRect(sf::IntRect(22, 0, 22, 31));
        if (Hrect.width < 550) {
            float speed = (2 * this->getDt()) * ((550 - Hrect.width) + 100);
            htp->setTextureRect(sf::IntRect(Hrect.left, Hrect.top, Hrect.width + speed, Hrect.height));
            Htp_full = false;
        } else
            Htp_full = true;
    } else if (Hrect.width > 0) {
        Htp_full = false;
        float speed = (2 * this->getDt()) * (Hrect.width + 100);
        htp->setTextureRect(sf::IntRect(Hrect.left, Hrect.top, Hrect.width - speed, Hrect.height));
    }
    return -1;
}

void cg::MainScene::onDelete() {

}

int cg::MainScene::onEvent(sf::Event event) {

    if (event.type == sf::Event::KeyPressed &&
        event.key.code == sf::Keyboard::Escape)
        exit(0);
    if (event.type == sf::Event::KeyPressed &&
        event.key.code == sf::Keyboard::Enter)
        iani += 0.5;
    if (event.type == sf::Event::MouseButtonPressed &&
        event.mouseButton.button == sf::Mouse::Left && quit_full)
        exit(0);
    if (event.type == sf::Event::MouseButtonPressed &&
        event.mouseButton.button == sf::Mouse::Left && play_full)
        return 2;
    if (event.type == sf::Event::MouseButtonPressed &&
        event.mouseButton.button == sf::Mouse::Left && Htp_full)
        return 4;
    return -1;
}

void cg::MainScene::onChange() {}