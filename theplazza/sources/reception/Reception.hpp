#ifndef B_CCP_400_MPL_4_1_THEPLAZZA_HUGO_ESCHLIMANN_RECEPTION_HPP
#define B_CCP_400_MPL_4_1_THEPLAZZA_HUGO_ESCHLIMANN_RECEPTION_HPP

#include <sys/types.h>
#include <unistd.h>
#include <iostream>
#include <memory>
#include <string>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <unordered_map>
#include <vector>
#include <array>
#include <tuple>
#include <cmath>
#include <algorithm>
#include <csignal>

#include <numeric>
#include "Order.hpp"
#include "PlazzaException.hpp"
#include "../Kitchen.hpp"

// regina XXL x2; fantasia M x3; margarita S x1
#include "../ipc/MessageQueue.hpp"
#include "../status/Status.hpp"

namespace Plazza {
    enum PizzaType {
        Regina = 1,
        Margarita = 2,
        Americana = 4,
        Fantasia = 8
    };

    enum PizzaSize {
        S = 1,
        M = 2,
        L = 4,
        XL = 8,
        XXL = 16
    };

    struct _infos_plazza {
        int orderLen;
        int kitchenLen;
    };

    struct _kitchensMessageQueue {
        Kitchen kitchen;
        MessageQueue messageQueue;
    };

    class Reception {
    public:
        Reception(int multiplier, int cooks, int time);
        ~Reception() = default;

        void run();
        void parseCommandLine(std::string& input);
        void printOrderStatus();

        void handlerSignal(int signal);

    private:
        int _multiplier;
        int _cooks;
        int _time;
        bool _isOpen;
        std::vector<Order> _order;
        int _numberOfKitchen;
        std::unique_ptr<MessageQueue> _messageQueue;
        std::vector<MessageQueue> _messagesQueues;

        std::array<std::string, 4> _pizzas;
        std::array<std::string, 5> _size;
    };
} // Plazza

#endif //B_CCP_400_MPL_4_1_THEPLAZZA_HUGO_ESCHLIMANN_RECEPTION_HPP
