#ifndef B_CCP_400_MPL_4_1_THEPLAZZA_HUGO_ESCHLIMANN_REGINA_HPP
#define B_CCP_400_MPL_4_1_THEPLAZZA_HUGO_ESCHLIMANN_REGINA_HPP

#include "IPizza.hpp"

namespace Plazza {
    class Regina : public IPizza {
    public:
        Regina() = default;
        ~Regina() override = default;
    };
} // Plazza

#endif //B_CCP_400_MPL_4_1_THEPLAZZA_HUGO_ESCHLIMANN_REGINA_HPP
