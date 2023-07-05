/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD07am-maxim.costa [WSL: Ubuntu]
** File description:
** Federation
*/

#ifndef FEDERATION_HPP_
#define FEDERATION_HPP_
#include <string>
#include "WarpSystem.hpp"

namespace Federation
{
    namespace Starfleet
    {
        class Ship {
          public:
            Ship(int length, int width, std::string name, short maxWarp);
            void setupCore(WarpSystem::Core *core);
            void checkCore();

          private:
            int _length;
            int _width;
            std::string _name;
            short _maxWarp;
            WarpSystem::Core *_core;
        };
    } // namespace Starfleet
    class Ship {
      public:
        Ship(int length, int width, std::string name);
        void setupCore(WarpSystem::Core *core);
        void checkCore();

      private:
        int _length;
        int _width;
        std::string _name;
        WarpSystem::Core *_core;
    };
} // namespace Federation

#endif /* !FEDERATION_HPP_ */
