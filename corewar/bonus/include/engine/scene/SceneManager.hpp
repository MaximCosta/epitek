/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/
#ifndef COREWAR_SCENEMANAGER_H
#define COREWAR_SCENEMANAGER_H

#include "Scene.hpp"
#include <iostream>
#include <vector>
#include <memory>



namespace cg {
    class SceneManager {

    private:
        sf::RenderWindow &window;
        std::map<int, std::shared_ptr<cg::Scene>> scenes;
        std::shared_ptr<cg::Scene> currentScene;

    public:
        SceneManager(sf::RenderWindow &window) : window(window) {
            this->currentScene = nullptr;
            this->scenes = {};
    }

        std::shared_ptr<cg::Scene> getCurrentScene();

        void setCurrentScene(std::shared_ptr<cg::Scene> scene);

        void setCurrentScene(int id);

        std::map<int, std::shared_ptr<cg::Scene>> getScenes(void);

        std::shared_ptr<cg::Scene> addScene(std::shared_ptr<cg::Scene> scene);

        void removeScene(std::shared_ptr<cg::Scene> scene);

        void removeScene(int id);

        std::shared_ptr<cg::Scene> getSceneFromId(int id);

        sf::RenderWindow &getWindow();

    };
}


#endif //COREWAR_SCENEMANAGER_H
