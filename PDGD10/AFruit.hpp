/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD10-maxim.costa [WSL: Ubuntu]
** File description:
** AFruit
*/

#ifndef AFruit_HPP
#define AFruit_HPP

#include "IFruit.hpp"

class AFruit : public IFruit {
  public:
    AFruit(std::string name = "", unsigned int vitamins = 0);
    virtual ~AFruit() = default;
    virtual unsigned int getVitamins() const;
    virtual std::string getName() const;
    virtual bool isPeeled() const;
    virtual void peel();

  protected:
    unsigned int _vitamins;
    std::string _name;
    bool _peeled;
};

#endif