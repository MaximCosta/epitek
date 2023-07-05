#ifndef B_CCP_400_MPL_4_1_THEPLAZZA_HUGO_ESCHLIMANN_KITCHEN_HPP
#define B_CCP_400_MPL_4_1_THEPLAZZA_HUGO_ESCHLIMANN_KITCHEN_HPP

#include <iostream>
#include <thread>
#include <vector>
#include <array>
#include <chrono>
#include <condition_variable>
#include <functional>

#include <sys/types.h>
#include <unistd.h>

#include "reception/Order.hpp"
#include "ipc/MessageQueue.hpp"
#include "ingredients/Ingredients.hpp"
#include "utils/Utils.hpp"
#include "../status/Status.hpp"

namespace Plazza {
    class Kitchen {
    public:
        Kitchen() = default;
        Kitchen(int multiplier, int cooks, int time, MessageQueue messageQueue);
        ~Kitchen() = default;

        Kitchen(const Kitchen& other) = default;
        Kitchen& operator=(const Kitchen& other) = default;
        Kitchen(Kitchen&& other) noexcept = default;
        Kitchen& operator=(Kitchen&& other) noexcept = default;

        void run();
        void cook(int start, int end);

        void cookRegina(std::mutex& mutex);
        void cookMargarita(std::mutex& mutex);
        void cookAmericana(std::mutex& mutex);
        void cookFantasia(std::mutex& mutex);

        std::unordered_map<std::string, std::size_t> getIngredient();
        std::unordered_map<std::string, std::function<void(std::mutex&)>> getPizzas();

    private:
        int _multiplier;
        int _cooks;
        int _time;
        int _pid;

        std::vector<Order> _pizzasToCook;
        // std::mutex _mutex;
        MessageQueue _messageQueue;

        std::vector<std::string> _pizzaNames;

        std::vector<std::thread> _cooksThread;

        int _msgId;
        std::string _tmpName;

        std::thread _ingredient;
        std::unordered_map<std::string, std::size_t> _ingredients;

        std::unordered_map<std::string, std::function<void(std::mutex&)>> _factoryPizzas;

        Status _status;
    };
} // Plazza

#endif //B_CCP_400_MPL_4_1_THEPLAZZA_HUGO_ESCHLIMANN_KITCHEN_HPP
