/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD06-maxim.costa [WSL: Ubuntu]
** File description:
** Student
*/

#include "Student.hpp"
#include <iostream>

Student::Student(std::string name) : name_(name), energy_(100)
{
    std::cout << "Student " << name_ << ": I'm ready to learn C++."
              << std::endl;
}

Student::~Student()
{
    std::cout << "Student " << name_
              << ": Wow, much learning today, very smart, such C++."
              << std::endl;
}

bool Student::learn(std::string text)
{
    if (energy_ < 42) {
        std::string str = text;
        size_t found = str.find("C++");
        while (found != std::string::npos) {
            str.replace(found, 3, "shit");
            found = str.find("C++");
        }
        std::cout << "Student " << name_ << ": " << str << std::endl;
        return false;
    } else {
        energy_ -= 42;
        std::cout << "Student " << name_ << ": " << text << std::endl;
        return true;
    }
}

void Student::drink(std::string drink)
{
    if (drink == "Red Bull") {
        energy_ += 32;
        std::cout << "Student " << name_ << ": Red Bull gives you wings!"
                  << std::endl;
    } else if (drink == "Monster") {
        energy_ += 64;
        std::cout << "Student " << name_ << ": Unleash The Beast!"
                  << std::endl;
    } else {
        energy_ += 1;
        std::cout << "Student " << name_ << ": ah, yes... enslaved moisture."
                  << std::endl;
    }
}
