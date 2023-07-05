/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD10-maxim.costa [WSL: Ubuntu]
** File description:
** AFruit
*/

#include "AFruit.hpp"

void AFruit::peel()
{
    this->_peeled = true;
}

bool AFruit::isPeeled() const
{
    return (this->_peeled);
}

unsigned int AFruit::getVitamins() const
{
    if (this->_peeled == true)
        return (this->_vitamins);
    return (0);
}

std::string AFruit::getName() const
{
    return (this->_name);
}

AFruit::AFruit(std::string name, unsigned int vitamins)
{
    this->_name = name;
    this->_vitamins = vitamins;
}