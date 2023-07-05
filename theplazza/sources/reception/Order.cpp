#include "Order.hpp"

namespace Plazza {
    Order::Order(std::string type, std::string size, std::size_t number)
        : _pizzaName(type), _pizzaSize(size), _pizzaNumber(number) {}

    std::string Order::getPizzaName() const {
        return _pizzaName;
    }

    std::string Order::getPizzaSize() const {
        return _pizzaSize;
    }

    std::size_t Order::getPizzaNumber() const {
        return _pizzaNumber;
    }

    std::string Order::serialize() const {
        return _pizzaName + " " + _pizzaSize + " " + std::to_string(_pizzaNumber);
    }

    Order& Order::deserialize(std::string& order) {
        std::string type;
        std::string size;
        std::size_t number;
        std::istringstream iss(order);
        iss >> type >> size >> number;
        return *(new Order(type, size, number));
    }

    bool Order::operator==(const Order& order) const {
        return _pizzaName == order._pizzaName && _pizzaSize == order._pizzaSize && _pizzaNumber == order._pizzaNumber;
    }

} // Plazza

std::ostream& operator<<(std::ostream& os, Plazza::Order& order) {
    os << order.getPizzaName() << ", " << order.getPizzaSize() << ", " << order.getPizzaNumber();
    return os;
}