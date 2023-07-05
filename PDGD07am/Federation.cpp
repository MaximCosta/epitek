/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD07am-maxim.costa [WSL: Ubuntu]
** File description:
** Federation
*/

#include "Federation.hpp"
#include <iostream>

namespace Federation
{
    namespace Starfleet
    {
        Ship::Ship(int length, int width, std::string name, short maxWarp)
            : _length(length), _width(width), _name(name), _maxWarp(maxWarp)
        {
            std::cout << "The ship USS " << _name << " has been finished."
                      << std::endl;
            std::cout << "It is " << _length << " m in length and " << _width
                      << " m in width." << std::endl;
            std::cout << "It can go to Warp " << _maxWarp << "!" << std::endl;
        }
        void Ship::setupCore(WarpSystem::Core *core)
        {
            _core = core;
            std::cout << "USS " << _name << ": The core is set." << std::endl;
        }
        void Ship::checkCore()
        {
            std::cout << "USS " << _name << ": The core is ";
            if (_core->checkReactor()->isStable()) {
                std::cout << "stable";
            } else {
                std::cout << "unstable";
            }
            std::cout << " at the time." << std::endl;
        }
    } // namespace Starfleet
    Ship::Ship(int length, int width, std::string name)
        : _length(length), _width(width), _name(name)
    {
        std::cout << "The independent ship " << _name
                  << " just finished its construction." << std::endl;
        std::cout << "It is " << _length << " m in length and " << _width
                  << " m in width." << std::endl;
    }
    void Ship::setupCore(WarpSystem::Core *core)
    {
        _core = core;
        std::cout << _name << ": The core is set." << std::endl;
    }

    void Ship::checkCore()
    {
        std::cout << _name << ": The core is ";
        if (_core->checkReactor()->isStable()) {
            std::cout << "stable";
        } else {
            std::cout << "unstable";
        }
        std::cout << " at the time." << std::endl;
    }
} // namespace Federation
