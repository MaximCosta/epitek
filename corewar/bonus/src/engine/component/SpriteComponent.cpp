/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/
#include <memory>
#include "../../../include/engine/Engine.hpp"
#include <cstdarg>

void cg::SpriteComponent::draw(sf::RenderWindow &window) {
    if (this->isVisible())
        window.draw(this->sprite);
}

bool cg::SpriteComponent::isHovered(sf::Vector2i mousePos) {
    return this->sprite.getGlobalBounds().contains(mousePos.x, mousePos.y);
}

void cg::SpriteComponent::setColor(sf::Color color) {
    this->sprite.setColor(color);
}

void cg::SpriteComponent::setPosition(sf::Vector2f position) {
    this->sprite.setPosition(position);
}

void cg::SpriteComponent::setScale(sf::Vector2f scale) {
    this->sprite.setScale(scale);
}

void cg::SpriteComponent::setRotation(float angle) {
    this->sprite.setRotation(angle);
}

sf::Vector2f cg::SpriteComponent::getPosition() {
    return this->sprite.getPosition();
}

sf::Vector2f cg::SpriteComponent::getScale() {
    return this->sprite.getScale();
}

float cg::SpriteComponent::getRotation() {
    return this->sprite.getRotation();
}

void cg::SpriteComponent::move(sf::Vector2f offset) {
    this->sprite.move(offset);
}

void cg::SpriteComponent::addRect(sf::IntRect rect) {
    this->rects.push_back(rect);
}

void cg::SpriteComponent::setRects(int count, ...) {
    std::vector<sf::IntRect> rects;
    std::va_list args;
    va_start(args, count);

    for (int i = 0; i < count; i++)
        rects.insert(rects.end(), va_arg(args, sf::IntRect));
    va_end(args);
    this->rects = rects;
}

void cg::SpriteComponent::nextRect() {
    if (this->rects.size() == this->currentRect)
        this->currentRect = 0;
    this->sprite.setTextureRect(this->rects[this->currentRect]);
    this->currentRect++;
}

std::vector<sf::IntRect> cg::SpriteComponent::getRects() {
    return this->rects;
}

sf::Color cg::SpriteComponent::getColor() {
    return this->sprite.getColor();
}

void cg::SpriteComponent::setTexture(sf::Texture &texture) {
    this->sprite.setTexture(texture);
}

void cg::SpriteComponent::setTextureRect(sf::IntRect rect) {
    this->sprite.setTextureRect(rect);
}

sf::IntRect cg::SpriteComponent::getTextureRect() {
    return this->sprite.getTextureRect();
}

const sf::Texture* cg::SpriteComponent::getTexture() {
    return this->sprite.getTexture();
}

void cg::SpriteComponent::setOrigin(sf::Vector2f origin) {
    this->sprite.setOrigin(origin);
}

sf::Vector2f cg::SpriteComponent::getOrigin() {
    return this->sprite.getOrigin();
}
