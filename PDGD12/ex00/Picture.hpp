/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD12-maxim.costa [WSL: Ubuntu]
** File description:
** Picture
*/

#ifndef PICTURE_HPP_
#define PICTURE_HPP_
#include <fstream> // pour lire les données d'un fichier
#include <iostream>
#include <sstream> // pour stocker les données dans une chaîne de caractères
#include <string>

class Picture {
  public:
    Picture(); // constructeur par défaut
    Picture(const std::string &file); // constructeur prenant le chemin d'accès au fichier en argument

    bool getPictureFromFile(const std::string &file); // pour lire les données d'un fichier

    std::string _data; // variable membre pour stocker les données de l'image

  protected:
  private:
};

#endif /* !PICTURE_HPP_ */