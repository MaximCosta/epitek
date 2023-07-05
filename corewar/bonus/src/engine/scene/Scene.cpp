/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/
#include "../../../include/engine/scene/Scene.hpp"
#include <memory>
#include "../../../include/engine/map/OrderedMap.hpp"

tsl::ordered_map<std::string, std::shared_ptr<cg::Component>>
cg::Scene::getComponents() {
    return this->components;
}

std::shared_ptr<cg::Component> cg::Scene::addComponent( std::shared_ptr<cg::Component> component) {
    if (this->components.count(component->getTag()) != 0)
        throw std::runtime_error("Component already exists");
    this->components.insert(std::pair<std::string,
                            std::shared_ptr<cg::Component>>(component->getTag(), component));
    return component;
}

sf::Clock cg::Scene::getClock() {
    return this->clock;
}

float cg::Scene::getDt() {
    return this->dt;
}

void cg::Scene::updateDt() {
    dt = this->clock.restart().asSeconds();
}

std::shared_ptr<cg::Component> cg::Scene::getComponentFromTag(std::string tag) {
    if (this->components.count(tag) == 0)
        return nullptr;
    return this->components.at(tag);
}

void cg::Scene::removeComponent(std::string tag) {
    if (this->components.count(tag) == 0)
        throw std::runtime_error("Component doesn't exist");
    this->components.erase(tag);
}

void cg::Scene::setName(std::string name) {
    this->name = name;
}

std::string cg::Scene::getName() {
    return this->name;
}

int cg::Scene::getId() {
    return this->id;
}

bool cg::Scene::isComponentHovered(std::shared_ptr<cg::Component> component) {
    return component->isHovered(sf::Mouse::getPosition());
}