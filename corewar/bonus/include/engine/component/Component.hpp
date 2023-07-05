/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/
#ifndef COMPONENT_HPP
#define COMPONENT_HPP
#include <string>
#include <vector>
#include "../EngineGraphicLib.hpp"
#include <memory>


namespace cg {
    class Component {

    private:
        std::string tag;
        bool visible;

    public:
        Component(std::string tag_) : tag(tag_), visible(true) {}

        std::string getTag();

        bool isVisible();

        void setVisible(bool visible);

        virtual void draw(sf::RenderWindow &window);

        virtual bool isHovered(sf::Vector2i mousePos);

    };

}


#endif //COMPONENT_HPP
