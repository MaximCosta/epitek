/*
** EPITECH PROJECT, 2023
** B_CCP_400_MPL_4_1_THEPLAZZA_HUGO_ESCHLIMANN_MAIN_CPP
** File description:
** main
*/

#include "reception/Reception.hpp"

int main(int ac, char **av) {
    if (ac == 2 && std::string(av[1]) == "--help") {
        std::cout << "USAGE: ./plazza <multiplier> <cooks> <time>" << std::endl;
        return EXIT_SUCCESS;
    }
    if (ac != 4) {
        std::cerr << "Wrong numbers of arguments" << std::endl;
        return 84;
    }

    try {
        int multiplier = std::stoi(av[1]);
        int cooks = std::stoi(av[2]);
        int time = std::stoi(av[3]);
        std::unique_ptr <Plazza::Reception> pizzeria = std::make_unique<Plazza::Reception>(multiplier, cooks, time);
        pizzeria->run();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return EXIT_SUCCESS;
}