/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD09-maxim.costa [WSL: Ubuntu]
** File description:
** Peasant
*/

#ifndef PEASANT_HPP
#define PEASANT_HPP

#include <iostream>
#include <string>

class Peasant {
  protected:
    std::string m_name;
    int m_power;
    int m_hp;

  public:
    Peasant(const std::string &name, int power);
    ~Peasant();
    const std::string &getName() const;
    int getPower() const;
    int getHp() const;
    int attack();
    int special();
    void rest();
    void damage(int damage);
};

#endif
