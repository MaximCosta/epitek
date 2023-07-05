/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD10-maxim.costa [WSL: Ubuntu]
** File description:
** Strawberry
*/

#ifndef STRAWBERRY_HPP_
#define STRAWBERRY_HPP_
#include "ABerry.hpp"

class Strawberry : public ABerry {
  public:
    Strawberry(std::string name = "strawberry", unsigned int vitamins = 6);
    virtual ~Strawberry() = default;
};

#endif /* !STRAWBERRY_HPP_ */
