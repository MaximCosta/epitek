#include "Reception.hpp"

namespace Plazza {
    Reception::Reception(int multiplier, int cooks, int time)
        : _multiplier(multiplier), _cooks(cooks), _time(time), _isOpen(true) {
        _pizzas = {"regina", "margarita", "americana", "fantasia"};
        _size = {"S", "M", "L", "XL", "XXL"};

        _numberOfKitchen = 0;
    }

    void Reception::run() {
        std::cout << "Bienvenue chez Pizza Mama !\n" << std::endl;
        std::string input;
        while (_isOpen) {
            std::getline(std::cin, input);
            if (std::cin.eof()) {
                _isOpen = false;
            }
            parseCommandLine(input);
            int maxPizzasPerKitchen = _cooks * 2;

            std::vector<Order> sortedOrders { _order };
            std::sort(sortedOrders.begin(), sortedOrders.end(), [](Order& order1, Order& order2) {
                return order1.getPizzaNumber() < order2.getPizzaNumber();
            });

            int numKitchens = std::ceil(std::accumulate(sortedOrders.begin(), sortedOrders.end(), 0, [](int acc, Order& order) {
                return acc + order.getPizzaNumber();
            }) / static_cast<double>(maxPizzasPerKitchen));

            std::vector<std::vector<Order>> tmpKitchens(numKitchens);

            // Vérifier si des cuisines sont déjà ouvertes et disponibles
            bool kitchenAvailable = false;
            for (int i = 0; i < numKitchens; i++) {
                if (!tmpKitchens[i].empty()) {
                    kitchenAvailable = true;
                    break;
                }
            }

            for (auto& order : sortedOrders) {
                int i = 0;
                int remainingPizzas = order.getPizzaNumber();

                while (remainingPizzas > 0) {
                    if (kitchenAvailable && !tmpKitchens[i].empty()) {
                        // Utiliser une cuisine disponible pour les pizzas restantes
                        int pizzasInKitchen = std::accumulate(tmpKitchens[i].begin(), tmpKitchens[i].end(), 0, [](int acc, Order& order) {
                            return acc + order.getPizzaNumber();
                        });

                        int pizzasToAdd = std::min(maxPizzasPerKitchen - pizzasInKitchen, remainingPizzas);
                        tmpKitchens[i].push_back(Order(order.getPizzaName(), order.getPizzaSize(), pizzasToAdd));
                        remainingPizzas -= pizzasToAdd;
                    } else {
                        // Créer une nouvelle cuisine
                        tmpKitchens[i].push_back(Order(order.getPizzaName(), order.getPizzaSize(), remainingPizzas));
                        remainingPizzas = 0;
                    }

                    i++;

                    if (i == numKitchens) {
                        i = 0;
                    }
                }
            }

            std::vector<_kitchensMessageQueue> kitchens;
            std::vector<std::pair<Kitchen, MessageQueue>> testKitchens;

            for (int i = 0; i < numKitchens; i++) {
                if (kitchenAvailable && tmpKitchens[i].empty()) {
                    continue;  // Ignorer les cuisines vides s'il y a des cuisines disponibles
                }

                MessageQueue messageQueue;
                messageQueue.createMessageQueue();
                
                Kitchen kitchen(_multiplier, _cooks, _time, messageQueue);

                for (auto& order : tmpKitchens[i]) {
                    if (order.getPizzaNumber() > 0) {
                        messageQueue.sendMessageOrder(order, Utils::KITCHEN_ORDER);
                    }
                }

                testKitchens.push_back(std::make_pair(std::move(kitchen), std::move(messageQueue)));
                testKitchens[i].first.run();
                messageQueue.receiveMessageNoWait(Utils::PIZZA_READY);

                // exit(0);
            }

            _order.clear();

        }
    }

    void Reception::parseCommandLine(std::string& input) {
        Status status;
        if (input.compare("status") == 0) {
            status.manageStatus();
        } else if (input.compare("exit") == 0) {
            _isOpen = false;
            exit(0);
        }

        if (input.back() == ';') {
            throw PlazzaException("Syntax Error !");
        }

        if (input.compare("status") == 0) {
            std::cout << "status" << std::endl;
            printOrderStatus();
        } else if (input.compare("exit") == 0) {
            _isOpen = false;
        } else {

            std::istringstream newInput(input);
            std::string token;
            while (std::getline(newInput, token, ';')) {
                std::istringstream ss(token);
                std::string type;
                std::string size;
                std::string number;

                ss >> type >> size >> number;
                if (std::find(_pizzas.begin(), _pizzas.end(), type) == _pizzas.end()) {
                    std::cerr << "Cette pizza n'est pas disponible. Veuillez nous excuser pour la gêne occasionnée." << std::endl;
                    continue;
                }
                if (std::find(_size.begin(), _size.end(), size) == _size.end()) {
                    std::cerr << "Cette taille n'est pas disponible. Veuillez nous excuser pour la gêne occasionnée." << std::endl;
                    continue;
                }
                number.erase(std::remove(number.begin(), number.end(), 'x'),number.end());
                if (std::stol(number) < 0) {
                    std::cerr << "Vous devez commander au moins une pizza." << std::endl;
                    continue;
                }
                _order.push_back(Order(type, size, std::stoi(number)));
            }
        }
    }

    void Reception::printOrderStatus() {
        std::cout << "status" << std::endl;
    }
} // Plazza