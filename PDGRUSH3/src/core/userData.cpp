/*
** EPITECH PROJECT, 2023
** tmp
** File description:
** user
*/

#include "../../include/core/core.hpp"
#include "../../include/lib/utils.hpp"

std::string IMonitorModule::User::getHostname() const
{
    std::string hostname;
    std::ifstream file("/proc/sys/kernel/hostname");
    std::string line;

    if (!file.is_open()) {
        return hostname;
    }
    while (getline(file, line)) {
        hostname = line;
    }
    file.close();
    return hostname;
}

std::string IMonitorModule::User::getUsername() const
{
    std::string username;
    std::ifstream file("/etc/passwd");
    std::string line;
    std::vector<std::string> splited;

    if (!file.is_open()) {
        return username;
    }
    while (getline(file, line)) {
        splited = split(line, ':');
        if (splited[2] == "1000" && splited[0] != "root" && splited[3] == "1000") {
            username = splited[0];
            break;
        }
    }
    file.close();
    return username;
}
