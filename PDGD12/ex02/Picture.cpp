/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD12-maxim.costa [WSL: Ubuntu]
** File description:
** Picture
*/

#include "Picture.hpp"

bool Picture::getPictureFromFile(const std::string& file)
{
    std::ifstream in(file);
    if (!in.is_open()) {
        _data = "ERROR";
        return false;
    }
    std::stringstream buffer;
    buffer << in.rdbuf();
    this->_data = buffer.str();
    in.close();
    return true;
}

Picture::Picture(const std::string& file)
{
    this->getPictureFromFile(file);
}

Picture::Picture()
{
    this->_data = "";
}

