/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD07am-maxim.costa [WSL: Ubuntu]
** File description:
** WarpSystem
*/

#include "WarpSystem.hpp"

namespace WarpSystem
{
    QuantumReactor::QuantumReactor() : _stability(true)
    {
    }
    bool QuantumReactor::isStable()
    {
        return _stability;
    }
    void QuantumReactor::setStability(bool stability)
    {
        _stability = stability;
    }

    Core::Core(QuantumReactor *coreReactor) : _coreReactor(coreReactor)
    {
    }
    QuantumReactor *Core::checkReactor()
    {
        return _coreReactor;
    }
} // namespace WarpSystem
