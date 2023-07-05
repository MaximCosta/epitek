#ifndef B_CCP_400_MPL_4_1_THEPLAZZA_HUGO_ESCHLIMANN_UTILS_HPP
#define B_CCP_400_MPL_4_1_THEPLAZZA_HUGO_ESCHLIMANN_UTILS_HPP

#include <iostream>
#include <string>
#include <thread>
#include <sstream>

namespace Plazza {
    class Utils {
    public:
        Utils() = default;
        ~Utils() = default;

        static const int KITCHEN_ORDER = 1;
        static const int KITCHEN_THREAD = 2;
        static const int KITCHEN_CLOSE = 3;
        static const int PIZZA_READY = 4;
        static std::string threadIdToString(const std::thread::id& threadId);
    };
} // Plazza

#endif //B_CCP_400_MPL_4_1_THEPLAZZA_HUGO_ESCHLIMANN_UTILS_HPP
