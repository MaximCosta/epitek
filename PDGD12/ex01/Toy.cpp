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
    return (_ToyPicture._data);
}

bool Toy::setAscii(const std::string &file)
{
    return (_ToyPicture.getPictureFromFile(file));
}

Toy::Toy(const Toy &other)
{
    this->_type = other._type;
    this->_name = other._name;
    this->_ToyPicture = other._ToyPicture;
}

Toy::Toy(ToyType type, const std::string &name, const std::string &file)
{
    this->_type = type;
    this->_name = name;
    this->setAscii(file);
}

Toy::Toy()
{
    this->_type = BASIC_TOY;
    this->_name = "toy";
    this->_ascii = "";
}

Toy &Toy::operator=(const Toy &other)
{
    this->_type = other._type;
    this->_name = other._name;
    this->_ToyPicture = other._ToyPicture;
    return *this;
}
