/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD12-maxim.costa [WSL: Ubuntu]
** File description:
** Picture
*/

#ifndef PICTURE_HPP_
    #define PICTURE_HPP_
    #include <iostream>
    #include <fstream>
    #include <string>
    #include <sstream>

class Picture {
    public:
        virtual ~Picture() = default;
        Picture();
        Picture(const std::string &file);
        Picture(const Picture &other) { this->_data = other._data; }

        bool getPictureFromFile(const std::string &file);

        std::string _data;

        Picture &operator=(const Picture &other) {
            this->_data = other._data;
            return *this;
        }
    protected:
    private:
};

#endif /* !PICTURE_HPP_ */
