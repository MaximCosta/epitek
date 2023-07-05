/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD13-maxim.costa [WSL: Ubuntu]
** File description:
** Algorithm
*/

#ifndef ALGORITHM_HPP_
#define ALGORITHM_HPP_

template <typename T> void swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T> T min(T a, T b)
{
    return (a < b ? a : b);
}

template <typename T> T max(T a, T b)
{
    return (a < b ? b : a);
}

template <typename T> T clamp(T value, T min, T max)
{
    return (value < min ? min : (value < max ? value : max));
}

#endif /* !ALGORITHM_HPP_ */
