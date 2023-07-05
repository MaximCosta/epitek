/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD10-maxim.costa [WSL: Ubuntu]
** File description:
** Orange
*/

#ifndef ORANGE_HPP_
#define ORANGE_HPP_
#include "ACitrus.hpp"

class Orange : public ACitrus {
  public:
    Orange(std::string name = "orange", unsigned int vitamins = 7);
    virtual ~Orange() = default;
};

#endif /* !ORANGE_HPP_ */
