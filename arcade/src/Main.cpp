/*
** EPITECH PROJECT, 2023
** Object-Oriented Programming |-| Arcade
** File description:
** Main cpp
*/

#include "Include.hpp"

int ErrorGestion(int ac, char **av)
{
    if (ac != 2) {
        std::cerr << "Bad Usage, Example: './arcade lib/arcade_ncurses.so'." << std::endl;
        return (84);
    }
    std::string file = av[1];
    if (file.substr(file.find_last_of('.') + 1) != "so") {
        std::cerr << "Invalid file format, only .so are allowed." << std::endl;
        return (84);
    }
    for (const auto& entry : std::experimental::filesystem::v1::directory_iterator("lib/")) {
        if (entry == file) {
            return (0);
        }
    }
    std::cerr << "Invalid Graphics Library, re-try after checking the 'lib' folder." << std::endl;
    return (84);
}

int main(int ac, char **av)
{
    if (ErrorGestion(ac, av) == 84) {
        return (84);
    }
    try {
        arcade::Core core = arcade::Core(av[1]);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return (84);
    }
    return (0);
}
