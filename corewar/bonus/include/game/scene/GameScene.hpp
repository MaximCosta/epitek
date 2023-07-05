/*
** EPITECH PROJECT, 2021
** template
** File description:
** template
*/

#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "../../engine/Engine.hpp"
extern "C" {
  #include "../../../../corewar/include/corewar.h"
}

namespace cg
{
    class GameScene : public Scene {
      private:
        std::shared_ptr<TextComponent> selectedByte;
        corewar_t *corewar;
        std::vector<std::shared_ptr<TextComponent>> bytesComponent;
        bool isPlaying;

      public:
        GameScene(
            corewar_t *corewar, int id_, std::string name_ = std::string("Default Scene Name"))
            : Scene(id_, name_), corewar(corewar)
        {
            selectedByte = nullptr;
            bytesComponent = {};
            isPlaying = false;
        }

        int onUpdate(sf::RenderWindow &window);

        void onInit(sf::RenderWindow &window);

        void onChange();

        void onDelete();

        int onEvent(sf::Event event);

        void loadGui();

        void fillChampionsProperties();

        void fillVmProperties();

        sf::Color getTeamColor(int textOwnerId, bool bold);

    };
} // namespace cg

#endif // GAMESCENE_H