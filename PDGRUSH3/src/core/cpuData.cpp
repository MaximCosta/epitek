/*
** EPITECH PROJECT, 2023
** Visual Studio Live Share (Espace de travail)
** File description:
** cpu
*/

#include "../../include/core/core.hpp"
#include "../../include/lib/utils.hpp"

namespace IMonitorModule
{
    Cpu::Cpu()
    {
        this->_cpuinfo = new components::Object();
    }

    void Cpu::updateCpu()
    {
        this->_cpuinfo->clearItems();

        std::ifstream file("/proc/cpuinfo");
        std::string line;

        if (file.is_open()) {
            while (std::getline(file, line)) {
                std::string name = line.substr(0, line.find(":"));
                std::string value = line.substr(line.find(":") + 1, line.size());
                name = remove_trailing_space_before(name);
                this->_cpuinfo->addItem(name, value);
            }
            file.close();
            this->updateProcessors();
        }
    }

    double Cpu::getCpuPercent() const
    {
        double percent = 0;
        for (unsigned int i = 0; i < this->_processors.size(); i++)
            percent += this->getProcessorPercent(this->_processors[i]);
        return (percent / this->_processors.size());
    }

    void Cpu::clearProcessors()
    {
        for (unsigned int i = 0; i < this->_processors.size(); i++)
            delete this->_processors[i];
        this->_processors.clear();
    }

    components::Object *Cpu::getCpuInfo() const { return this->_cpuinfo; }
    std::vector<components::Object *>Cpu::getProcessors() const { return this->_processors; }
    void Cpu::updateProcessors()
    {
        if (!this->_cpuinfo) return;
        this->clearProcessors();

        std::vector<components::Item *> items = this->_cpuinfo->getItems();
        int index = -1;
        for (int i = 0; i < this->_cpuinfo->count(); i++) {
            if (items[i]->getName() == "processor") {
                components::Object *processor = new components::Object();
                processor->addItem("processor", items[i]->getData());
                this->_processors.push_back(processor);
                index++;
            } else
                this->_processors[index]->addItem(items[i]->getName(), items[i]->getData());
        }
    }

    template <typename T>
    T Cpu::convertTo(const std::string &value) const
    {
        std::stringstream ss(value);
        T result;
        return ss >> result ? result : 0;
    }

    double Cpu::getProcessorPercent(const components::Object *processor) const {
        std::string modelName = processor->getItem("model name")->getData();
        std::string currentMhz = processor->getItem("cpu MHz")->getData();
        std::string maxMhz = modelName.substr(modelName.find("@") + 1, modelName.size());
        double current = this->convertTo<double>(currentMhz);
        double max = this->convertTo<double>(maxMhz);
        return ((current * 100) / (max*1000));
    }
}
