/*
** EPITECH PROJECT, 2021
** template
** File description:
** template
*/

#ifndef LOADINGSCENE_H
#define LOADINGSCENE_H

#include "../../engine/Engine.hpp"

namespace cg {
    class LoadingScene : public Scene {

    public:
      LoadingScene(int id_,
                  std::string name_ = std::string("Default Scene Name"))
            : Scene(id_, name_) {}

        int onUpdate(sf::RenderWindow &window);

        void onInit(sf::RenderWindow &window);

        void onChange();

        void onDelete();

        int onEvent(sf::Event event);
    };
}

#endif // LOADINGSCENE_H