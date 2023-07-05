/*
** EPITECH PROJECT, 2023
** tmp
** File description:
** network
*/

#include "../../include/core/core.hpp"
#include "../../include/lib/utils.hpp"

namespace IMonitorModule
{
    Network::Network()
    {
    }

    Network::~Network()
    {
    }

    void Network::updateNetwork()
    {
        this->_networkinfo.clear();

        std::ifstream file("/proc/net/dev");
        std::string line;
        int i = 0;

        if (file.is_open()) {
            while (std::getline(file, line)) {
                if (i < 2) {
                    i++;
                    continue;
                }
                std::vector<std::string> data = split(line, ' ');
                for (auto it = data.begin(); it != data.end();) {
                    if (it->empty())
                        it = data.erase(it);
                    else
                        it++;
                }
                components::Object *obj = new components::Object();
                obj->setId(data[0].substr(0, data[0].size() - 1));
                obj->addItem("Bytes", data[1]);
                obj->addItem("Packets", data[2]);
                obj->addItem("Errors", data[3]);
                obj->addItem("Drop", data[4]);
                obj->addItem("Fifo", data[5]);
                obj->addItem("Frame", data[6]);
                obj->addItem("Compressed", data[7]);
                obj->addItem("Multicast", data[8]);
                obj->addItem("Bytes", data[9]);
                obj->addItem("Packets", data[10]);
                obj->addItem("Errors", data[11]);
                obj->addItem("Drop", data[12]);
                obj->addItem("Fifo", data[13]);
                obj->addItem("Colls", data[14]);
                obj->addItem("Carrier", data[15]);
                obj->addItem("Compressed", data[16]);
                this->_networkinfo.push_back(obj);
            }
            file.close();
        }
    }

    std::vector<components::Object *> Network::getNetworkAllInfo() const
    {
        return this->_networkinfo;
    }


}
