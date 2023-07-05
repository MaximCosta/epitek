/*
** EPITECH PROJECT, 2023
** Visual Studio Live Share (Espace de travail)
** File description:
** object
*/

#ifndef OBJECT_HPP_
    #define OBJECT_HPP_
    #include <iostream>
    #include <string>
    #include <vector>

namespace components {

    class Item {
        public:
            Item(std::string name, std::string data = "");
            ~Item() {};

            // Getters
            std::string getName() const;
            std::string getData() const;

        private:
            std::string _name;
            std::string _data;
    };

    class Object {
        public:
            Object() {};
            ~Object() {};

            void addItem(Item *item);
            void addItem(std::string name, std::string data);
            void setId(std::string id);
            void clearItems();
            int count() const;
            Item *getItem(std::string name) const;
            std::string getId() const;
            std::vector<Item *> getItems() const;

        private:
            std::vector<Item *> _items;
            std::string _id;
    };

}



#endif /* !OBJECT_HPP_ */
