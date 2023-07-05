/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/
#include <memory>
#include "../../../include/engine/Engine.hpp"
#include <cstdarg>

void cg::ShapeComponent::draw(sf::RenderWindow &window) {
    if (this->isVisible())
        window.draw(this->shape);
}

bool cg::ShapeComponent::isHovered(sf::Vector2i mousePos) {
    return this->shape.getGlobalBounds().contains(mousePos.x, mousePos.y);
}

void cg::ShapeComponent::setFillColor(sf::Color color) {
    this->shape.setFillColor(color);
}

void cg::ShapeComponent::setPosition(sf::Vector2f position) {
    this->shape.setPosition(position);
}

void cg::ShapeComponent::setScale(sf::Vector2f scale) {
    this->shape.setScale(scale);
}

void cg::ShapeComponent::setRotation(float angle) {
    this->shape.setRotation(angle);
}

sf::Vector2f cg::ShapeComponent::getPosition() {
    return this->shape.getPosition();
}

sf::Vector2f cg::ShapeComponent::getScale() {
    return this->shape.getScale();
}

float cg::ShapeComponent::getRotation() {
    return this->shape.getRotation();
}

void cg::ShapeComponent::move(sf::Vector2f offset) {
    this->shape.move(offset);
}

void cg::ShapeComponent::addRect(sf::IntRect rect) {
    this->rects.push_back(rect);
}

void cg::ShapeComponent::setRects(int count, ...) {
    std::vector<sf::IntRect> rects;
    std::va_list args;
    va_start(args, count);

    for (int i = 0; i < count; i++)
        rects.insert(rects.end(), va_arg(args, sf::IntRect));
    va_end(args);
    this->rects = rects;
}

void cg::ShapeComponent::nextRect() {
    if (this->rects.size() == this->currentRect)
        this->currentRect = 0;
    //this->shape.setTextureRect(this->rects[this->currentRect]);
    this->currentRect++;
}

std::vector<sf::IntRect> cg::ShapeComponent::getRects() {
    return this->rects;
}

sf::Color cg::ShapeComponent::getFillColor() {
    return this->shape.getFillColor();
}

void cg::ShapeComponent::setTexture(sf::Texture &texture) {
    //this->shape.setTexture(texture);
}

void cg::ShapeComponent::setTextureRect(sf::IntRect rect) {
    //this->shape.setTextureRect(rect);
}

sf::IntRect cg::ShapeComponent::getTextureRect() {
    return this->shape.getTextureRect();
}

const sf::Texture* cg::ShapeComponent::getTexture() {
    return this->shape.getTexture();
}

void cg::ShapeComponent::setOrigin(sf::Vector2f origin) {
    this->shape.setOrigin(origin);
}

sf::Vector2f cg::ShapeComponent::getOrigin() {
    return this->shape.getOrigin();
}
