/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD09-maxim.costa [WSL: Ubuntu]
** File description:
** Knight
*/

#include "Knight.hpp"
#include <iostream>

Knight::Knight(const std::string &name, int power) : Peasant(name, power)
{
    std::cout << getName() << " vows to protect the kingdom." << std::endl;
}

int Knight::attack()
{
    if (getHp() <= 0) {
        std::cout << getName() << " is out of combat." << std::endl;
        return 0;
    }

    if (getPower() < 10) {
        std::cout << getName() << " is out of power." << std::endl;
        return 0;
    }

    m_power -= 10;
    std::cout << getName() << " strikes with his sword." << std::endl;
    return 20;
}

int Knight::special()
{
    if (getHp() <= 0) {
        std::cout << getName() << " is out of combat." << std::endl;
        return 0;
    }

    if (getPower() < 30) {
        std::cout << getName() << " is out of power." << std::endl;
        return 0;
    }

    m_power -= 30;
    std::cout << getName() << " impales his enemy." << std::endl;
    return 50;
}

void Knight::rest()
{
    if (getHp() <= 0) {
        std::cout << getName() << " is out of combat." << std::endl;
        return;
    }

    m_power += 50;
    if (m_power > 100) {
        m_power = 100;
    }
    std::cout << getName() << " eats." << std::endl;
}

Knight::~Knight()
{
    std::cout << getName() << " takes off his armor." << std::endl;
}
