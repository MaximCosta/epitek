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

static const std::string LOADING_BACK = "./bonus/resources/Loading_back.png";
static const std::string LOADING_FRONT = "./bonus/resources/Load_front.png";

void cg::LoadingScene::onInit(sf::RenderWindow &window) {

    //ADD LOAD BACK
    std::shared_ptr <cg::SpriteComponent> load = std::make_shared<cg::SpriteComponent>(
        cg::SpriteComponent("Load", LOADING_BACK));
    load->setOrigin(sf::Vector2f{933, 29});
    load->setPosition(sf::Vector2f(960, 1030));

    std::shared_ptr <cg::SpriteComponent> load_front = std::make_shared<cg::SpriteComponent>(
        cg::SpriteComponent("Load_front", LOADING_FRONT));
    load_front->setPosition(sf::Vector2f(29, 1003));
    load_front->setTextureRect(sf::IntRect{0, 0, 0, 58});

    this->addComponent(load);
    this->addComponent(load_front);
}

int cg::LoadingScene::onUpdate(sf::RenderWindow &window) {

    std::shared_ptr <cg::SpriteComponent> load =
        std::dynamic_pointer_cast<cg::SpriteComponent>(
            this->getComponentFromTag("Load_front"));

    static bool passed = false;

    static float value = 1;
    float i = value * this->getDt();
    sf::IntRect rect = load->getTextureRect();
    i *= (1900 - (29 + rect.width)) / 100;
    load->setTextureRect(sf::IntRect{rect.left, rect.top, (int)(rect.width + i), 58});
    if (rect.width >= 1600)
        return 3;
    value *= 1.05;
    return -1;
}
void cg::LoadingScene::onDelete() {

}

int cg::LoadingScene::onEvent(sf::Event event) {

    return -1;
}

void cg::LoadingScene::onChange() {}