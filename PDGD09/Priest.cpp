/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD09-maxim.costa [WSL: Ubuntu]
** File description:
** Priest
*/

#include "Priest.hpp"
#include <iostream>

Priest::Priest(const std::string &name, int power) : Enchanter(name, power) {
    std::cout << name << " enters in the order." << std::endl;
}

Priest::~Priest() {
    std::cout << m_name << " finds peace." << std::endl;
}

void Priest::rest() {
    if (m_hp == 0) {
        std::cout << m_name << " is out of combat." << std::endl;
        return;
    }
    std::cout << m_name << " prays." << std::endl;
    m_power = 100;
    m_hp = 100;
}
