/*
** EPITECH PROJECT, 2023
** tmp
** File description:
** split
*/

#include "../../include/lib/utils.hpp"

std::vector<std::string> split(const std::string str, char delim)
{
    std::vector<std::string> ret;
    std::stringstream ss(str);
    std::string token;

    while(std::getline(ss, token, delim)) {
        ret.push_back(token);
    }
    return ret;
}

std::string remove_trailing_space_before(std::string s)
{
    s.erase(s.find_last_not_of(" \n\r\t") + 1);
    return s;
}

std::string remove_trailing_space_after(std::string s)
{
    int pos = s.find_first_not_of(" \n\r\t") - 1;
    if (pos >= 0)
        s.erase(0, pos);
    return s;
}
