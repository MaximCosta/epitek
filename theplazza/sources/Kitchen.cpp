#include "Kitchen.hpp"

namespace Plazza {
    Kitchen::Kitchen(int multiplier, int cooks, int time, MessageQueue messageQueue) : _multiplier(multiplier), _cooks(cooks), _time(time), _messageQueue(messageQueue) {

        _factoryPizzas = {
            {"regina", [this](std::mutex& mutex) { cookRegina(mutex); }},
            {"margarita", [this]( std::mutex& mutex) { cookMargarita(mutex); }},
            {"americana", [this](std::mutex& mutex) { cookAmericana(mutex); }},
            {"fantasia", [this](std::mutex& mutex) { cookFantasia(mutex); }},
        };

        _ingredients = {
            {"doe", 5},
            {"tomato", 5},
            {"gruyere", 5},
            {"ham", 5},
            {"mushrooms", 5},
            {"steak", 5},
            {"eggplant", 5},
            {"goat cheese", 5},
            {"chief love", 5}
        };  
    }

    std::unordered_map<std::string, std::function<void(std::mutex&)>> Kitchen::getPizzas()
    {
        return _factoryPizzas;
    }

    std::unordered_map<std::string, std::size_t> Kitchen::getIngredient()
    {
        return _ingredients;
    }

    void Kitchen::run() {
        _pid = fork();
        if (_pid == 0) {
            std::cout << "Kitchen: " << getpid() << " created !" << std::endl;

            std::string resultOrder;
            while (resultOrder != "false") {
                resultOrder = _messageQueue.receiveMessageOrderNoWait(Utils::KITCHEN_ORDER);
                for (std::size_t i = 0; resultOrder != "false" && i < Order::deserialize(resultOrder).getPizzaNumber(); i++) {
                    _pizzaNames.push_back(Order::deserialize(resultOrder).getPizzaName());
                }
            }

            _cooksThread.reserve(_cooks);
            std::mutex mutex;
            std::cout << "cooks : " << _cooks << std::endl;
            for (int i = 0; i < _cooks; i++) {
                _cooksThread.emplace_back([&, this]() {
                    while (true) {
                        std::string pizzaName;
                        {
                            std::lock_guard<std::mutex> lock(mutex);
                            if (_pizzaNames.empty()) {
                                break;
                            }
                            pizzaName = _pizzaNames.front();
                            std::cout << "Cook " << Utils::threadIdToString(std::this_thread::get_id())
                                      << " started processing pizza: " << pizzaName << std::endl;
                            _pizzaNames.erase(_pizzaNames.begin());

                            
                        }
                        _factoryPizzas.find(pizzaName)->second(mutex);
                        std::cout << "Cook " << Utils::threadIdToString(std::this_thread::get_id())
                                << " finished processing pizza: " << pizzaName << std::endl;
                    }
                });
            }

            for (auto& cook : _cooksThread) {
                cook.join();
            }

            std::chrono::seconds duration(5);
            std::this_thread::sleep_for(duration);
            std::cout << "Kitchen: " << getpid() << " closed !" << std::endl;
            exit(0);
        }
    }

    void Kitchen::cookRegina(std::mutex& mutex) {
        std::lock_guard<std::mutex> lock(mutex);

        _ingredients["doe"] -= 1;
        _ingredients["tomato"] -= 1;
        _ingredients["gruyere"] -= 1;
        _ingredients["ham"] -= 1;
        _ingredients["mushrooms"] -= 1;

        std::chrono::seconds duration(2 * _multiplier);
        std::this_thread::sleep_for(duration);
        std::cout << "Regina cooked !" << std::endl;
       _messageQueue.sendMessage("Regina", Utils::PIZZA_READY);
    }

    void Kitchen::cookMargarita(std::mutex& mutex) {
        std::lock_guard<std::mutex> lock(mutex);

        _ingredients["doe"] -= 1;
        _ingredients["tomato"] -= 1;
        _ingredients["gruyere"] -= 1;

        std::chrono::seconds duration(1 * _multiplier);
        std::this_thread::sleep_for(duration);
        std::cout << "Margarita cooked !" << std::endl;
//        _messageQueue->sendMessage("Margarita", Utils::PIZZA_READY);
    }

    void Kitchen::cookAmericana(std::mutex& mutex) {
        std::lock_guard<std::mutex> lock(mutex);

        _ingredients["doe"] -= 1;
        _ingredients["tomato"] -= 1;
        _ingredients["gruyere"] -= 1;
        _ingredients["steak"] -= 1;

        std::chrono::seconds duration(2 * _multiplier);
        std::this_thread::sleep_for(duration);
        std::cout << "Americana cooked !" << std::endl;
//        _messageQueue->sendMessage("Americana", Utils::PIZZA_READY);
    }

    void Kitchen::cookFantasia(std::mutex& mutex) {
        std::lock_guard<std::mutex> lock(mutex);

        _ingredients["doe"] -= 1;
        _ingredients["tomato"] -= 1;
        _ingredients["eggplant"] -= 1;
        _ingredients["goat cheese"] -= 1;
        _ingredients["chief love"] -= 1;

        std::chrono::seconds duration(4 * _multiplier);
        std::this_thread::sleep_for(duration);
        std::cout << "Fantasia cooked !" << std::endl;
//        _messageQueue->sendMessage("Fantasia", Utils::PIZZA_READY);
    }
} // Plazza