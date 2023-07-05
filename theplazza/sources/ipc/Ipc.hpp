#ifndef B_CCP_400_MPL_4_1_THEPLAZZA_HUGO_ESCHLIMANN_IPC_HPP
#define B_CCP_400_MPL_4_1_THEPLAZZA_HUGO_ESCHLIMANN_IPC_HPP

#include <iostream>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <cstring>
#include <memory>

#include "PlazzaException.hpp"

namespace Plazza {
    class IPC {
    public:
        virtual ~IPC() = default;

        virtual void sendMessage(std::string message, int type) = 0;
        virtual std::string receiveMessage(unsigned int type) = 0;
    };
} // Plazza

#endif //B_CCP_400_MPL_4_1_THEPLAZZA_HUGO_ESCHLIMANN_IPC_HPP
