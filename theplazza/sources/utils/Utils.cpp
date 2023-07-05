#include "Utils.hpp"

namespace Plazza {
    std::string Utils::threadIdToString(const std::thread::id& id) {
        std::ostringstream oss;
        oss << id;
        return oss.str();
    }
} // Plazza