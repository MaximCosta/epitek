/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD12-maxim.costa [WSL: Ubuntu]
** File description:
** Toy
*/

#ifndef TOY_HPP_
#define TOY_HPP_
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "Picture.hpp"

class Toy {
  public:
    enum ToyType {
        BASIC_TOY,
        ALIEN,
    };
    virtual ~Toy() = default;
    Toy(ToyType type, const std::string &name, const std::string &file);
    Toy();
    Toy(const Toy &other)
    {
        this->_type = other._type;
        this->_name = other._name;
        this->_ascii = other._ascii;
    }

    ToyType getType() const;
    std::string getName() const;
    std::string getAscii() const;
    void setName(const std::string &name);
    bool setAscii(const std::string &file);
    Toy &operator=(const Toy &other)
    {
        _type = other._type;
        _name = other._name;
        _ascii = other._ascii;
        return *this;
    }

  protected:
  private:
    ToyType _type;
    Picture ToyPicture;
    std::string _name;
    std::string _ascii;
};

#endif /* !TOY_HPP_ */
