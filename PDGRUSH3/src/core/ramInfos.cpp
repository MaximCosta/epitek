/*
** EPITECH PROJECT, 2023
** tmp
** File description:
** ram
*/

#include "../../include/core/core.hpp"
#include "../../include/lib/utils.hpp"

namespace IMonitorModule
{
    Ram::Ram()
    {
        this->_raminfo = new components::Object();
    }

    Ram::~Ram()
    {
        delete this->_raminfo;
    }

    void Ram::updateRam()
    {
        this->_raminfo->clearItems();

        std::ifstream file("/proc/meminfo");
        std::string line;

        if (file.is_open()) {
            while (std::getline(file, line)) {
                std::string name = line.substr(0, line.find(":"));
                std::string value = line.substr(line.find(":") + 1, line.size());
                name = remove_trailing_space_before(name);
                value = remove_trailing_space_after(value);
                this->_raminfo->addItem(name, value);
            }
            file.close();
        }
    }

    components::Item *Ram::getTotalRam() const
    {
        return this->_raminfo->getItem("MemTotal");
    }

    components::Item *Ram::getFreeRam() const
    {
        return this->_raminfo->getItem("MemFree");
    }

    components::Item *Ram::getUsedRam() const
    {
        return new components::Item("MemUsed", (std::to_string((std::stoi(this->getTotalRam()->getData()) - std::stoi(this->getAvailableRam()->getData())) / 1024)) + " MB");
    }

    components::Item *Ram::getSharedRam() const
    {
        return this->_raminfo->getItem("Shmem");
    }

    components::Item *Ram::getBufferRam() const
    {
        return this->_raminfo->getItem("Buffers");
    }

    components::Item *Ram::getCacheRam() const
    {
        return this->_raminfo->getItem("Cached");
    }

    components::Item *Ram::getAvailableRam() const
    {
        return this->_raminfo->getItem("MemAvailable");
    }

    components::Item *Ram::getSwapTotal() const
    {
        return this->_raminfo->getItem("SwapTotal");
    }

    components::Item *Ram::getSwapFree() const
    {
        return this->_raminfo->getItem("SwapFree");
    }

    components::Item *Ram::getSwapUsed() const
    {
        return new components::Item("SwapUsed", (std::to_string((std::stoi(this->getSwapTotal()->getData()) - std::stoi(this->getSwapFree()->getData())) / 1024)) + " MB");
    }
}
