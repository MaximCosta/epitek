/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/
#ifndef COREWAR_SCENE_HPP
#define COREWAR_SCENE_HPP
#include <memory>
#include <string>
#include <vector>
#include "../../../include/engine/map/OrderedMap.hpp"
#include "../component/Component.hpp"
#include "../EngineGraphicLib.hpp"

namespace cg {
    class Scene {

    private:
        int id;
        std::string name;
        tsl::ordered_map<std::string, std::shared_ptr<cg::Component>> components;
        sf::Clock clock;
        float dt;

    public:
        Scene(int id_, std::string name_ = std::string("Default Scene Name")) : id(id_), name(name_) {
            components = {};
            clock = sf::Clock();
            dt = 0.0f;
        }

        virtual void onInit(sf::RenderWindow &window) = 0;

        virtual int onUpdate(sf::RenderWindow &window) = 0;

        virtual void onChange() = 0;

        virtual void onDelete() = 0;

        virtual int onEvent(sf::Event event) = 0;

        sf::Clock getClock();

        float getDt();

        void updateDt();

        tsl::ordered_map<std::string, std::shared_ptr<cg::Component>> getComponents();

        std::shared_ptr<cg::Component> addComponent(std::shared_ptr<cg::Component> component);

        void removeComponent(std::string tag);

        std::shared_ptr<cg::Component> getComponentFromTag(std::string tag);

        void setName(std::string name);

        std::string getName();

        int getId();

        bool isComponentHovered(std::shared_ptr<cg::Component> component);

    };

}


#endif //COREWAR_SCENE_HPP
