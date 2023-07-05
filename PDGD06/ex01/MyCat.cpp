/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD06-maxim.costa [WSL: Ubuntu]
** File description:
** MyCat
*/

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[]) {
    if (argc == 1) {
        std::string input;
        while (std::getline(std::cin, input)) {
            std::cout << input << std::endl;
        }
    } else {
        for (int i = 1; i < argc; i++) {
            std::ifstream file(argv[i]);
            if (!file.is_open()) {
                std::cerr << "MyCat: " << argv[i] << ": No such file or directory" << std::endl;
                return 84;
            }
            std::string input;
            while (std::getline(file, input)) {
                std::cout << input << std::endl;
            }
            file.close();
        }
    }
    return 0;
}
