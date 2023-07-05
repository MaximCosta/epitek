/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/

#include "../../include/game/Game.hpp"

void start_graphic_mode(corewar_t *corewar) {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Corewar",
                            sf::Style::Fullscreen);
    window.setFramerateLimit(120);
    window.setMouseCursorVisible(false);
    cg::Engine engine(window);
    engine.InitEngine(window);

    std::shared_ptr<cg::MainScene> mainScene = std::make_shared<cg::MainScene>(cg::MainScene(1, "Ma Super Scene Principal"));
    std::shared_ptr<cg::LoadingScene> loadingScene = std::make_shared<cg::LoadingScene>(cg::LoadingScene(2, "Ma Super Scene de chargement"));
    std::shared_ptr<cg::GameScene> gameScene = std::make_shared<cg::GameScene>(cg::GameScene(corewar, 3, "Ma Super Scene de jeu"));
    std::shared_ptr<cg::HowToPlayScene> howToScene = std::make_shared<cg::HowToPlayScene>(cg::HowToPlayScene(4, "Ma Super Scene de HowToPlay"));
    engine.getSceneManager()->addScene(mainScene);
    engine.getSceneManager()->addScene(loadingScene);
    engine.getSceneManager()->addScene(howToScene);
    engine.getSceneManager()->addScene(gameScene);
    engine.run();
}
