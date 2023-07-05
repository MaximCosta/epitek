/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD10-maxim.costa [WSL: Ubuntu]
** File description:
** ANut
*/

#include "ANut.hpp"

ANut::ANut(std::string name, unsigned int vitamins) : AFruit(name, vitamins)
{
    this->_peeled = false;
}