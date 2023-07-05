/*
** EPITECH PROJECT, 2021
** main
** File description:
** main.c
*/
#ifndef TEXTCOMPONENT_HPP
#define TEXTCOMPONENT_HPP

#include <string>
#include <vector>
#include "../EngineGraphicLib.hpp"
#include "Component.hpp"
#include <memory>

namespace cg {
    class TextComponent : public Component {

    private:
        std::shared_ptr<sf::Text> text;
        std::shared_ptr<sf::Font> font;

    public:

        ////////////////////////////////////////////////////////////
        /// \brief Construct the sprite component from a source texture
        ///
        /// \param tag Component tag
        /// \param texture Source texture
        ///
        ////////////////////////////////////////////////////////////
        TextComponent(std::string tag, std::string text, std::string fontPath)
            : Component(tag) {
            this->font = std::make_shared<sf::Font>(sf::Font());
            this->font->loadFromFile(fontPath);
            this->text = std::make_shared<sf::Text>(sf::Text(text, *this->font));
        }

/*        ////////////////////////////////////////////////////////////
        /// \brief Construct the sprite component from a source texture
        ///
        /// \param tag Component tag
        /// \param texture Source texture
        ///
        ////////////////////////////////////////////////////////////
        TextComponent(std::string tag, std::string text, sf::Font font)
            : Component(tag), text(sf::Text(text, font)) {}*/

/*        ////////////////////////////////////////////////////////////
        /// \brief Construct the sprite component from a source texture
        ///
        /// \param tag Component tag
        /// \param texture Source texture
        /// \param characterSize character size
        ///
        ////////////////////////////////////////////////////////////
        TextComponent(std::string tag, std::string text, sf::Font font,
                      int characterSize) : Component(tag), text(
            sf::Text(text, font, characterSize)) {}*/

/*        ////////////////////////////////////////////////////////////
        /// \brief Construct the sprite component from a source sprite
        ///
        /// \param tag Component tag
        /// \param text Source text
        ///
        ////////////////////////////////////////////////////////////
        TextComponent(std::string tag, sf::Text text) : Component(tag),
                                                        text(text) {}*/

        void setString(std::string text);

        void setFont(sf::Font font);

        void setCharacterSize(int characterSize);

        void setPosition(sf::Vector2f position);

        void setPosition(float x, float y);

        void setRotation(float angle);

        void setScale(sf::Vector2f scale);

        void setScale(float x, float y);

        void setOrigin(sf::Vector2f origin);

        bool isHovered(sf::Vector2i mousePos);

        void setOrigin(float x, float y);

        void setOutlineColor(sf::Color color);

        void setOutlineThickness(float thickness);

        sf::FloatRect getLocalBounds();

        std::string getString();

        void setStyle(sf::Text::Style style);

        void setString(const std::vector<std::string> &strings);

        void move(sf::Vector2f offset);

        void move(int x, int y);

        void setLineSpacing(float spacing);

        void setFillColor(sf::Color color);

        void draw(sf::RenderWindow &window);
    };

}


#endif //TEXTCOMPONENT_HPP
