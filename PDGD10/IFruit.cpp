/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD10-maxim.costa [WSL: Ubuntu]
** File description:
** IFruit
*/

#include "IFruit.hpp"
#include <iostream>

std::ostream &operator<<(std::ostream &os, const IFruit &fruit)
{
    os << "[name: \"" << fruit.getName() << "\", ";
    os << "vitamins: " << fruit.getVitamins() << ", ";
    os << "peeled: " << (fruit.isPeeled() ? "true]" : "false]");
    return os;
}
