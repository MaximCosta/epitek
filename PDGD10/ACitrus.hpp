/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD10-maxim.costa [WSL: Ubuntu]
** File description:
** ACitrus
*/

#ifndef ACitrus_HPP
#define ACitrus_HPP

#include "AFruit.hpp"

class ACitrus : public AFruit {
  public:
    ACitrus(std::string name = "", unsigned int vitamins = 0);
    virtual ~ACitrus() = default;
};

#endif