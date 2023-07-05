/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD10-maxim.costa [WSL: Ubuntu]
** File description:
** ABerry
*/

#include "ABerry.hpp"

ABerry::ABerry(std::string name, unsigned int vitamins)
    : AFruit(name, vitamins)
{
    this->_peeled = true;
}