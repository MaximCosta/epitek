/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD09-maxim.costa [WSL: Ubuntu]
** File description:
** Wizard
*/

#ifndef ENCHANTER_HPP
#define ENCHANTER_HPP

#include "Peasant.hpp"

class Enchanter : public Peasant {
  public:
    Enchanter(const std::string &name, int power);
    int attack();
    int special();
    void rest();
    ~Enchanter();
};

#endif
