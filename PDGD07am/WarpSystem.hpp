/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD07am-maxim.costa [WSL: Ubuntu]
** File description:
** WarpSystem
*/

#ifndef WARPSYSTEM_HPP_
#define WARPSYSTEM_HPP_

namespace WarpSystem
{
    class QuantumReactor {
      public:
        QuantumReactor();
        bool isStable();
        void setStability(bool stability);

      private:
        bool _stability;
    };

    class Core {
      public:
        Core(QuantumReactor *coreReactor);
        QuantumReactor *checkReactor();

      private:
        QuantumReactor *_coreReactor;
    };
} // namespace WarpSystem

#endif /* !WARPSYSTEM_HPP_ */
