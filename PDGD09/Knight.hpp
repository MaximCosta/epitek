/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD09-maxim.costa [WSL: Ubuntu]
** File description:
** Knigh
*/

#ifndef KNIGHT_HPP
#define KNIGHT_HPP

#include "Peasant.hpp"

class Knight : public Peasant {
  public:
    Knight(const std::string &name, int power);
    int attack();
    int special();
    void rest();
    ~Knight();
};

#endif
