/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/
#include "../../../include/engine/Engine.hpp"
#include "../../../include/game/Game.hpp"

static const std::string LOADING_BACK = "./bonus/resources/Loading_back.png";
static const std::string LOADING_FRONT = "./bonus/resources/Load_front.png";
static const std::string HOWTOPLAY = "./bonus/resources/HowToPlayBackground.png";
static const std::string RETURN = "./bonus/resources/Return.png";
static const std::string CURSOR = "./bonus/resources/Cursor.png";

bool MouseisPress = false;

void cg::HowToPlayScene::onInit(sf::RenderWindow &window) {
    std::shared_ptr<cg::SpriteComponent> HowToPlay =
        std::make_shared<cg::SpriteComponent>(
            cg::SpriteComponent("HowToPlay", HOWTOPLAY));
    HowToPlay->setPosition(sf::Vector2f(50, 75));

    std::shared_ptr<cg::SpriteComponent> Return =
        std::make_shared<cg::SpriteComponent>(
            cg::SpriteComponent("Return", RETURN));
    Return->setTextureRect(sf::IntRect(0, 0, 237, 58));
    Return->setPosition(sf::Vector2f(50, 980));

    // ADD Cursor
    std::shared_ptr <cg::SpriteComponent> cursor = std::make_shared<cg::SpriteComponent>(
        cg::SpriteComponent("Cursor", CURSOR));
    cursor->setTextureRect(sf::IntRect(0, 0, 22, 31));

    this->addComponent(HowToPlay);
    this->addComponent(Return);
    this->addComponent(cursor);
}

int cg::HowToPlayScene::onUpdate(sf::RenderWindow &window) {
    // GET cursor
    std::shared_ptr<cg::SpriteComponent> cursor =
        std::dynamic_pointer_cast<cg::SpriteComponent>(
            this->getComponentFromTag("Cursor"));
    std::shared_ptr<cg::SpriteComponent> Return =
        std::dynamic_pointer_cast<cg::SpriteComponent>(
            this->getComponentFromTag("Return"));

    // UPDATE CURSOR
    cursor->setPosition(
        sf::Vector2f(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y));
    cursor->setTextureRect(sf::IntRect(0, 0, 22, 31));

    if (this->isComponentHovered(Return)) {
        Return->setTextureRect(sf::IntRect(237, 0, 237, 58));
        if (MouseisPress)
            return 1;
    } else
        Return->setTextureRect(sf::IntRect(0, 0, 237, 58));
    return -1;
}
void cg::HowToPlayScene::onDelete() {

}

int cg::HowToPlayScene::onEvent(sf::Event event) {

    if (event.type == sf::Event::MouseButtonPressed)
        MouseisPress = true;
    else
        MouseisPress = false;
    return -1;
}

void cg::HowToPlayScene::onChange() {}