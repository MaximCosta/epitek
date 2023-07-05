/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/
#include <memory>
#include "../../../include/engine/Engine.hpp"
#include <cstdarg>

void cg::TextComponent::draw(sf::RenderWindow &window) {
    if (this->isVisible())
        window.draw(*this->text);
}

bool cg::TextComponent::isHovered(sf::Vector2i mousePos) {
    return this->text->getGlobalBounds().contains(mousePos.x, mousePos.y);
}

void cg::TextComponent::move(sf::Vector2f offset) {
    this->text->move(offset);
}

void cg::TextComponent::move(int x, int y) {
    this->text->move(x, y);
}

sf::FloatRect cg::TextComponent::getLocalBounds() {
    return this->text->getLocalBounds();
}

std::string cg::TextComponent::getString() {
    return this->text->getString();
}

void cg::TextComponent::setString(std::string text) {
    this->text->setString(text);
}

void cg::TextComponent::setFont(sf::Font font) {
    this->text->setFont(font);
}

void cg::TextComponent::setCharacterSize(int characterSize) {
    this->text->setCharacterSize(characterSize);
}

void cg::TextComponent::setPosition(sf::Vector2f position) {
    this->text->setPosition(position);
}

void cg::TextComponent::setPosition(float x, float y) {
    this->text->setPosition(x, y);
}

void cg::TextComponent::setRotation(float angle) {
    this->text->setRotation(angle);
}

void cg::TextComponent::setScale(sf::Vector2f scale) {
    this->text->setScale(scale);
}

void cg::TextComponent::setScale(float x, float y) {
    this->text->setScale(x, y);
}

void cg::TextComponent::setOrigin(sf::Vector2f origin) {
    this->text->setOrigin(origin);
}

void cg::TextComponent::setOrigin(float x, float y) {
    this->text->setOrigin(x, y);
}

void cg::TextComponent::setOutlineColor(sf::Color color) {
    this->text->setOutlineColor(color);
}

void cg::TextComponent::setOutlineThickness(float thickness) {
    this->text->setOutlineThickness(thickness);
}

void cg::TextComponent::setStyle(sf::Text::Style style) {
    this->text->setStyle(style);
}

void cg::TextComponent::setLineSpacing(float spacing) {
    this->text->setLineSpacing(spacing);
}

void cg::TextComponent::setFillColor(sf::Color color) {
    this->text->setFillColor(color);
}
