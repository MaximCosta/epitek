/*
** EPITECH PROJECT, 2023
** tmp
** File description:
** data_times
*/

#include "../../include/core/core.hpp"

std::string IMonitorModule::DataTimes::getZone() const
{
    std::string zone;
    std::ifstream file("/etc/timezone");
    std::string line;

    if (file.is_open())
    {
        while (getline(file, line))
        {
            zone = line;
        }
        file.close();
    }
    return zone;
}

std::string IMonitorModule::DataTimes::getLocaltime() const
{
    time_t t = time(NULL);
    struct tm *time = localtime(&t);
    return
        (time->tm_hour < 10 ? "0" : "") + std::to_string(time->tm_hour) +
        ":" + (time->tm_min < 10 ? "0" : "") + std::to_string(time->tm_min) +
        ":" + (time->tm_sec < 10 ? "0" : "") + std::to_string(time->tm_sec);
}

std::string IMonitorModule::DataTimes::getDate() const
{
    time_t t = time(NULL);
    struct tm *time = localtime(&t);
    return
            (time->tm_mday < 10 ? "0" : "") + std::to_string(time->tm_mday) + "/" +
        (time->tm_mon + 1 < 10 ? "0" : "") + std::to_string(time->tm_mon + 1) + "/" +
                    std::to_string(time->tm_year + 1900);
}

std::string IMonitorModule::DataTimes::getUptime() const
{
    std::string uptime;
    std::ifstream file("/proc/uptime");
    std::string line;

    if (!file.is_open()) {
        return uptime;
    }
    while (getline(file, line)) {
        uptime = line;
    }
    file.close();
    std::string days = std::to_string(std::stoi(uptime.substr(0, uptime.find('.'))) / 60 / 60 / 24);
    std::string hours = std::to_string(std::stoi(uptime.substr(0, uptime.find('.'))) / 60 / 60 % 24);
    std::string minutes = std::to_string(std::stoi(uptime.substr(0, uptime.find('.'))) / 60 % 60);
    std::string seconds = std::to_string(std::stoi(uptime.substr(0, uptime.find('.'))) % 60);
    return days + "d " + hours + "h " + minutes + "m " + seconds + "s";
}
