/*
** EPITECH PROJECT, 2023
** Visual Studio Live Share (Espace de travail)
** File description:
** kernel
*/

#include "../../include/core/core.hpp"

std::string IMonitorModule::Kernel::getKernelVersion() const
{
    std::string version;
    std::ifstream file("/proc/version");
    std::string line;

    if (file.is_open())
    {
        while (getline(file, line))
        {
            version = line;
        }
        file.close();
    }
    return version;
}

std::string IMonitorModule::Kernel::getKernelName() const
{
    std::string name;
    std::ifstream file("/proc/sys/kernel/ostype");
    std::string line;

    if (file.is_open()) {
        while (getline(file, line))
            name = line;
        file.close();
    }
    return name;
}

std::string IMonitorModule::Kernel::getKernelRelease() const
{
    std::string release;
    std::ifstream file("/proc/sys/kernel/osrelease");
    std::string line;

    if (file.is_open()) {
        while (getline(file, line))
            release = line;
        file.close();
    }
    return release;
}

std::string IMonitorModule::Kernel::getKernelMachine() const
{
    std::string machine;
    std::ifstream file("/proc/sys/kernel/hostname");
    std::string line;

    if (file.is_open()) {
        while (getline(file, line))
            machine = line;
        file.close();
    }
    return machine;
}

std::string IMonitorModule::Kernel::getKernelDomain() const
{
    std::string domain;
    std::ifstream file("/proc/sys/kernel/domainname");
    std::string line;

    if (file.is_open()) {
        while (getline(file, line))
            domain = line;
        file.close();
    }
    return domain;
}
