/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD12-maxim.costa [WSL: Ubuntu]
** File description:
** Picture
*/

#include "Picture.hpp"

bool Picture::getPictureFromFile(const std::string &file)
{
    std::ifstream in(file); // on ouvre le fichier
    if (!in.is_open()) { // si le fichier n'est pas ouvert
        _data = "ERROR"; // on stocke "ERROR" dans _data
        return false; // on retourne false
    }
    std::stringstream buffer; // on utilise un stringstream pour stocker les données du fichier
    buffer << in.rdbuf(); // on lit les données du fichier
    this->_data = buffer.str(); // on stocke les données dans _data
    in.close(); // on ferme le fichier
    return true; // on retourne true pour indiquer que la lecture s'est bien déroulée
}

Picture::Picture(const std::string &file)
{
    getPictureFromFile(file); // on appelle la fonction getPictureFromFile pour lire les données du fichier
}

Picture::Picture()
{
    this->_data = ""; // on initialise _data à une chaîne vide
}