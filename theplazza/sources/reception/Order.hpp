#ifndef B_CCP_400_MPL_4_1_THEPLAZZA_HUGO_ESCHLIMANN_ORDER_HPP
#define B_CCP_400_MPL_4_1_THEPLAZZA_HUGO_ESCHLIMANN_ORDER_HPP

#include <iostream>
#include <string>
#include <sstream>

namespace Plazza {
    class Order {
    public:
        Order(std::string type, std::string size, std::size_t number);
        ~Order() = default;

        std::string getPizzaName() const;
        std::string getPizzaSize() const;
        std::size_t getPizzaNumber() const;

        std::string serialize() const;
        static Order& deserialize(std::string& order);

        bool operator==(const Order& order) const;

    private:
        std::string _pizzaName;
        std::string _pizzaSize;
        std::size_t _pizzaNumber;
    };
} // Plazza

std::ostream& operator<<(std::ostream& os, Plazza::Order& order);

#endif //B_CCP_400_MPL_4_1_THEPLAZZA_HUGO_ESCHLIMANN_ORDER_HPP
