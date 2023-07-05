#ifndef B_CCP_400_MPL_4_1_THEPLAZZA_HUGO_ESCHLIMANN_PLAZZAEXCEPTION_HPP
#define B_CCP_400_MPL_4_1_THEPLAZZA_HUGO_ESCHLIMANN_PLAZZAEXCEPTION_HPP

#include <iostream>
#include <exception>

namespace Plazza {
    class PlazzaException : public std::exception {
    public:
        PlazzaException(const std::string& message) noexcept : _message(message) {}
        ~PlazzaException() noexcept override = default;

        const char* what() const noexcept override { return _message.c_str(); }

    private:
        std::string _message;
    };
} // Plazza

#endif //B_CCP_400_MPL_4_1_THEPLAZZA_HUGO_ESCHLIMANN_PLAZZAEXCEPTION_HPP
