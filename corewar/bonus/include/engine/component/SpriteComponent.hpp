/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/
#ifndef SPRITECOMPONENT_HPP
#define SPRITECOMPONENT_HPP
#include <string>
#include <vector>
#include "../EngineGraphicLib.hpp"
#include "Component.hpp"
#include <memory>

namespace cg {
    class SpriteComponent : public Component{

    private:
        sf::Sprite sprite;
        std::shared_ptr<sf::Texture> texture;
        std::vector<sf::IntRect> rects;
        int currentRect;

    public:

        ////////////////////////////////////////////////////////////
        /// \brief Construct the sprite component from a source texture
        ///
        /// \param tag Component tag
        /// \param texture Source texture
        ///
        ////////////////////////////////////////////////////////////
        SpriteComponent(std::string tag, std::string texturePath) : Component(tag), sprite(sf::Sprite())  {
            texture = std::make_shared<sf::Texture>(sf::Texture());
            texture->loadFromFile(texturePath);
            sprite.setTexture(*texture);
            rects = {};
            currentRect = 0;
        }

/*        ////////////////////////////////////////////////////////////
        /// \brief Construct the sprite component from a source sprite
        ///
        /// \param tag Component tag
        /// \param sprite Source sprite
        ///
        ////////////////////////////////////////////////////////////
        SpriteComponent(std::string tag, sf::Sprite &sprite) : Component(tag), sprite(sprite), texture(sprite.getTexture()){}*/


        void setRects(int count, ...);

        std::vector<sf::IntRect> getRects();

        void addRect(sf::IntRect rect);

        void nextRect();

        void draw(sf::RenderWindow &window);

        void setColor(sf::Color color);

        void setPosition(sf::Vector2f position);

        void setScale(sf::Vector2f scale);

        void setRotation(float angle);

        sf::Vector2f getPosition();

        sf::Vector2f getScale();

        float getRotation();

        sf::Color getColor();

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


#endif //SPRITECOMPONENT_HPP
