/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD09-maxim.costa [WSL: Ubuntu]
** File description:
** Priest
*/

#ifndef PRIEST_HPP
#define PRIEST_HPP

#include "Enchanter.hpp"

class Priest : public Enchanter {
  public:
    Priest(const std::string &name, int power);
    ~Priest();
    void rest();
};

#endif
