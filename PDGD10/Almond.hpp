/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD10-maxim.costa [WSL: Ubuntu]
** File description:
** Almond
*/

#ifndef ALMOND_HPP_
    #define ALMOND_HPP_
    #include "ANut.hpp"

class Almond : public ANut {
    public:
        Almond(std::string name = "almond", unsigned int vitamins = 2);
        virtual ~Almond() = default;
};

#endif /* !ALMOND_HPP_ */
