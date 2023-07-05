/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD09-maxim.costa [WSL: Ubuntu]
** File description:
** Peasant
*/

#include "Peasant.hpp"

Peasant::Peasant(const std::string &name, int power)
    : m_name(name), m_power(power), m_hp(100)
{
    std::cout << m_name << " goes for an adventure." << std::endl;
}

const std::string &Peasant::getName() const
{
    return m_name;
}

int Peasant::getPower() const
{
    return m_power;
}

int Peasant::getHp() const
{
    return m_hp;
}

int Peasant::attack()
{
    if (m_hp <= 0) {
        std::cout << m_name << " is out of combat." << std::endl;
        return 0;
    }

    if (m_power < 10) {
        std::cout << m_name << " is out of power." << std::endl;
        return 0;
    }

    m_power -= 10;
    std::cout << m_name << " tosses a stone." << std::endl;
    return 5;
}

int Peasant::special()
{
    if (m_hp <= 0) {
        std::cout << m_name << " is out of combat." << std::endl;
        return 0;
    }

    std::cout << m_name << " doesn't know any special move." << std::endl;
    return 0;
}

void Peasant::rest()
{
    if (m_hp <= 0) {
        std::cout << m_name << " is out of combat." << std::endl;
        return;
    }

    m_power += 30;
    if (m_power > 100) {
        m_power = 100;
    }
    std::cout << m_name << " takes a nap." << std::endl;
}

void Peasant::damage(int damage)
{
    if (m_hp <= 0) {
        std::cout << m_name << " is out of combat." << std::endl;
        return;
    }
    m_hp -= damage;
    if (m_hp < 0)
        m_hp = 0;
    if (m_hp == 0) {
        std::cout << m_name << " is out of combat." << std::endl;
    } else {
        std::cout << m_name << " takes " << damage << " damage." << std::endl;
    }
}

Peasant::~Peasant()
{
    std::cout << m_name << " is back to his crops." << std::endl;
}
