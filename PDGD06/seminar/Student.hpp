/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD06-maxim.costa [WSL: Ubuntu]
** File description:
** Student
*/

#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>

class Student {
  public:
    Student(std::string name);
    ~Student();
    bool learn(std::string text);
    void drink(std::string drink);

  private:
    std::string name_;
    int energy_;
};

#endif
