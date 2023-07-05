/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD09-maxim.costa [WSL: Ubuntu]
** File description:
** Wizard
*/

#include "Enchanter.hpp"

Enchanter::Enchanter(const std::string &name, int power) : Peasant(name, power)
{
    std::cout << m_name << " learns magic from his spellbook." << std::endl;
}

Enchanter::~Enchanter()
{
    std::cout << m_name << " closes his spellbook." << std::endl;
}

int Enchanter::attack()
{
    if (m_hp <= 0) {
        std::cout << m_name << " is out of combat." << std::endl;
        return 0;
    }
    std::cout << m_name << " doesn't know how to fight." << std::endl;
    return 0;
}

int Enchanter::special()
{
    if (m_hp <= 0) {
        std::cout << m_name << " is out of combat." << std::endl;
        return 0;
    }
    if (m_power < 50) {
        std::cout << m_name << " is out of power." << std::endl;
        return 0;
    }
    m_power -= 50;
    std::cout << m_name << " casts a fireball." << std::endl;
    return 99;
}

void Enchanter::rest()
{
    if (m_hp <= 0) {
        std::cout << m_name << " is out of combat." << std::endl;
        return;
    }
    std::cout << m_name << " meditates." << std::endl;
    m_power = 100;
}
