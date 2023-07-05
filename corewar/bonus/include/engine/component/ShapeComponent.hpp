/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/
#ifndef SHAPECOMPONENT_HPP
#define SHAPECOMPONENT_HPP
#include <string>
#include <vector>
#include "../EngineGraphicLib.hpp"
#include "Component.hpp"
#include <memory>

namespace cg {
    class ShapeComponent : public Component{

    private:
        sf::Shape &shape;
        std::shared_ptr<sf::Texture> texture;
        std::vector<sf::IntRect> rects;
        int currentRect;

    public:

        ////////////////////////////////////////////////////////////
        /// \brief Construct the shape component from a source texture
        ///
        /// \param tag Component tag
        /// \param texture Source texture
        ///
        ////////////////////////////////////////////////////////////
        ShapeComponent(std::string tag, sf::Shape &shape, std::string texturePath) : Component(tag), shape(shape) {
            texture = std::make_shared<sf::Texture>(sf::Texture());
            texture->loadFromFile(texturePath);
            //shape.setTexture((const sf::Texture*) (*texture));
            rects = {};
            currentRect = 0;
        }

        void setRects(int count, ...);

        std::vector<sf::IntRect> getRects();

        void addRect(sf::IntRect rect);

        void nextRect();

        void draw(sf::RenderWindow &window);

        void setFillColor(sf::Color color);

        void setPosition(sf::Vector2f position);

        void setScale(sf::Vector2f scale);

        void setRotation(float angle);

        sf::Vector2f getPosition();

        sf::Vector2f getScale();

        float getRotation();

        sf::Color getFillColor();

        void setTexture(sf::Texture &texture);

        void setTextureRect(sf::IntRect rect);

        sf::IntRect getTextureRect();

        const sf::Texture* getTexture();

        void setOrigin(sf::Vector2f origin);

        bool isHovered(sf::Vector2i mousePos);

        sf::Vector2f getOrigin();

        void move(sf::Vector2f offset);

    };

}


#endif //SHAPECOMPONENT_HPP
