/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD10-maxim.costa [WSL: Ubuntu]
** File description:
** Lemon
*/

#ifndef LEMON_HPP_
    #define LEMON_HPP_
    #include "ACitrus.hpp"

class Lemon : public ACitrus {
    public:
        Lemon(std::string name = "lemon", unsigned int vitamins = 4);
        virtual ~Lemon() = default;
};

#endif /* !LEMON_HPP_ */
