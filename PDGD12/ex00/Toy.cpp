/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD12-maxim.costa [WSL: Ubuntu]
** File description:
** Toy
*/

#include "Toy.hpp"

void Toy::setName(const std::string &name)
{
    this->_name = name;
}

std::string Toy::getName() const
{
    return this->_name;
}

Toy::ToyType Toy::getType() const
{
    return (_type);
}

std::string Toy::getAscii() const
{
    return (ToyPicture._data);
}

bool Toy::setAscii(const std::string &file)
{
    return (ToyPicture.getPictureFromFile(file));
}

Toy::Toy(ToyType type, const std::string &name, const std::string &file)
{
    this->_type = type;
    this->_name = name;
    this->_ascii = this->setAscii(file);
}

Toy::Toy()
{
    this->_type = BASIC_TOY;
    this->_name = "toy";
    this->_ascii = "";
}
