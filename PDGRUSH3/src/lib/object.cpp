/*
** EPITECH PROJECT, 2023
** Visual Studio Live Share (Espace de travail)
** File description:
** object
*/

#include "../../include/lib/object.hpp"

namespace components
{
    void Object::addItem(Item *item) { this->_items.push_back(item); };
    void Object::clearItems() { this->_items.clear();};
    int Object::count() const { return this->_items.size(); };
    void Object::setId(std::string id) { this->_id = id; };
    std::string Object::getId() const { return this->_id; };
    std::vector<Item *> Object::getItems() const { return this->_items; };
    Item *Object::getItem(std::string name) const
    {
        for (unsigned int i = 0; i < this->_items.size(); i++) {
            if (this->_items[i]->getName() == name)
                return this->_items[i];
        }
        return new Item("", "");
    };
    void Object::addItem(std::string name, std::string data) {
        Item *item = new Item(name, data);
        this->addItem(item);
    };

    Item::Item(std::string name, std::string data)
    {
        this->_name = name;
        this->_data = data;
    };

    std::string Item::getName() const { return this->_name; };
    std::string Item::getData() const { return this->_data; };

} // namespace components
