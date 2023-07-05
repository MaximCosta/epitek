/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD10-maxim.costa [WSL: Ubuntu]
** File description:
** IFruit
*/

#ifndef IFruit_hpp
#define IFruit_hpp
#include <iostream>
#include <string>

class IFruit {
  public:
    virtual ~IFruit() = default;
    virtual unsigned int getVitamins() const = 0;
    virtual std::string getName() const = 0;
    virtual bool isPeeled() const = 0;
    virtual void peel() = 0;
};

std::ostream &operator<<(std::ostream &os, const IFruit &fruit);

#endif /* IFruit_hpp */
