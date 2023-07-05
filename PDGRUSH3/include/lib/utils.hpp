/*
** EPITECH PROJECT, 2023
** Visual Studio Live Share (Espace de travail)
** File description:
** utils
*/

#ifndef UTILS_HPP_
    #define UTILS_HPP_
    #include <string>
    #include <vector>
    #include <sstream>
    #include <iostream>
    #include <fstream>
    #include <algorithm>
    #include <iterator>
    #include <iomanip>
    #include <unistd.h>

std::vector<std::string> split(std::string str, char sep);
std::string remove_trailing_space_before(std::string s);
std::string remove_trailing_space_after(std::string s);

#endif /* !UTILS_HPP_ */
