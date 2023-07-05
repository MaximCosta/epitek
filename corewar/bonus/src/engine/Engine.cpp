/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/
#include "stdio.h"
#include "../../include/engine/Engine.hpp"


void cg::Engine::InitEngine(sf::RenderWindow &renderWindow) {
    sceneManager = std::make_shared<cg::SceneManager>(cg::SceneManager(renderWindow));

}

std::shared_ptr<cg::SceneManager> cg::Engine::getSceneManager() {
    return sceneManager;
}

void cg::Engine::run() {
    std::shared_ptr<cg::Scene> currentScene = sceneManager->getCurrentScene();

    while (window.isOpen()) {
        currentScene = sceneManager->getCurrentScene();
        for (auto &scene : sceneManager->getScenes())
            scene.second->updateDt();
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (currentScene) {
                int changeScene = this->getSceneManager()->getCurrentScene()->onEvent(event);
                if (changeScene != -1)
                    this->getSceneManager()->setCurrentScene(changeScene);
            }
        }
        window.clear();
        if (currentScene) {
            int changeScene = this->getSceneManager()->getCurrentScene()->onUpdate(window);
            if (changeScene != -1)
                this->getSceneManager()->setCurrentScene(changeScene);
        }
        for (auto &it : currentScene->getComponents()) {
            it.second->draw(this->window);
        }
        window.display();
    }
}