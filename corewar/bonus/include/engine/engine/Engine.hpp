/*
** EPITECH PROJECT, 2021
** template
** File description:
** template
*/

#ifndef ENGINE_ENGINE_H
#define ENGINE_ENGINE_H
#include "../scene/SceneManager.hpp"
#include "../EngineGraphicLib.hpp"

namespace cg {
    class Engine {

    private:
        std::shared_ptr<SceneManager> sceneManager;
        sf::RenderWindow &window;

    public:

        Engine(sf::RenderWindow &window) : window(window) {}

        void InitEngine(sf::RenderWindow &window);

        sf::RenderWindow &getWindow(void);

        std::shared_ptr<SceneManager> getSceneManager(void);

        void run(void);

    };

}


#endif // ENGINE_ENGINE_H