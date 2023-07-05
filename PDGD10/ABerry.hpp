/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD10-maxim.costa [WSL: Ubuntu]
** File description:
** ABerry
*/

#ifndef ABERRY_HPP_
#define ABERRY_HPP_
#include "AFruit.hpp"

class ABerry : public AFruit {
  public:
    ABerry(std::string name = "", unsigned int vitamins = 0);
    virtual ~ABerry() = default;
};

#endif /* !ABERRY_HPP_ */
