/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/
#include <memory>
#include "../../../include/engine/component/Component.hpp"
#include <iostream>
void cg::Component::draw(sf::RenderWindow &window) {
    throw std::runtime_error("Component not implemented");
}

bool cg::Component::isHovered(sf::Vector2i mousePos){
    throw std::runtime_error("Component not implemented");
}

void cg::Component::setVisible(bool visible) {
    this->visible = visible;
}

bool cg::Component::isVisible() {
    return this->visible;
}

std::string cg::Component::getTag() {
    return this->tag;
}