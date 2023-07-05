/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/

#include "../../../include/engine/scene/SceneManager.hpp"

std::shared_ptr<cg::Scene> cg::SceneManager::getCurrentScene() {
    return currentScene;
}

void cg::SceneManager::setCurrentScene(std::shared_ptr<cg::Scene> scene) {
    currentScene = scene;
}

void cg::SceneManager::setCurrentScene(int id) {
    currentScene = this->getSceneFromId(id);
}

std::map<int, std::shared_ptr<cg::Scene>> cg::SceneManager::getScenes() {
    return this->scenes;
}

std::shared_ptr<cg::Scene> cg::SceneManager::addScene(std::shared_ptr<Scene> scene) {
    if (this->scenes.count(scene->getId()) != 0)
        return nullptr;
    if (this->currentScene == nullptr)
        this->currentScene = scene;
    scene->onInit(window);
    this->scenes.insert(std::pair<int, std::shared_ptr<cg::Scene>>(scene->getId(), scene));
    return scene;
}

void cg::SceneManager::removeScene(std::shared_ptr<cg::Scene> scene) {
    this->scenes.erase(scene->getId());
}

void cg::SceneManager::removeScene(int id) {
    this->scenes.erase(id);
}

std::shared_ptr<cg::Scene> cg::SceneManager::getSceneFromId(int id) {
    if (this->scenes.count(id) == 0)
        throw std::runtime_error("Scene not found");
    return this->scenes[id];
}

sf::RenderWindow &cg::SceneManager::getWindow() {
    return this->window;
}