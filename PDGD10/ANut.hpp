/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD10-maxim.costa [WSL: Ubuntu]
** File description:
** ANut
*/

#ifndef ANUT_HPP_
#define ANUT_HPP_
#include "AFruit.hpp"

class ANut : public AFruit {
  public:
    ANut(std::string name = "", unsigned int vitamins = 0);
    virtual ~ANut() = default;
};

#endif /* !ANUT_HPP_ */
