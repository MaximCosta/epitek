#ifndef B_CCP_400_MPL_4_1_THEPLAZZA_HUGO_ESCHLIMANN_AMERICANA_HPP
#define B_CCP_400_MPL_4_1_THEPLAZZA_HUGO_ESCHLIMANN_AMERICANA_HPP

#include "IPizza.hpp"

namespace Plazza {
    class Americana : public IPizza {
    public:
        Americana() = default;
        ~Americana() override = default;
    };
} // Plazza

#endif //B_CCP_400_MPL_4_1_THEPLAZZA_HUGO_ESCHLIMANN_AMERICANA_HPP
