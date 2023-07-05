/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGRUSH3-nathan.catalan
** File description:
** ncursesMagement
*/

#include "../../include/ncurses/ncursesApplications.hpp"
#include <ncurses.h>

ncursesApplications::ncursesApplications()
{
    this->_isRunning = true;
    this->_starter_tasks = 0;
}

ncursesApplications::~ncursesApplications()
{
    this->_isRunning = false;
}

bool ncursesApplications::isRunning() const
{
    return this->_isRunning;
}

void ncursesApplications::init()
{
    initscr();
    nodelay(stdscr, true);
    keypad(stdscr, true);
    noecho();
    cbreak();
    curs_set(0);
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(5, COLOR_BLUE, COLOR_BLACK);
    init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(7, COLOR_CYAN, COLOR_BLACK);
    init_pair(8, COLOR_WHITE, COLOR_RED);
    init_pair(9, COLOR_WHITE, COLOR_GREEN);
    init_pair(10, COLOR_WHITE, COLOR_YELLOW);
    init_pair(11, COLOR_WHITE, COLOR_BLUE);
    init_pair(12, COLOR_WHITE, COLOR_MAGENTA);
    init_pair(13, COLOR_WHITE, COLOR_CYAN);
    init_pair(14, COLOR_BLACK, COLOR_WHITE);
    init_pair(15, COLOR_BLACK, COLOR_RED);
    init_pair(16, COLOR_BLACK, COLOR_GREEN);
    init_pair(17, COLOR_BLACK, COLOR_YELLOW);
    init_pair(18, COLOR_BLACK, COLOR_BLUE);
    init_pair(19, COLOR_BLACK, COLOR_MAGENTA);
    init_pair(20, COLOR_BLACK, COLOR_CYAN);
    init_pair(21, COLOR_RED, COLOR_WHITE);
    init_pair(22, COLOR_GREEN, COLOR_WHITE);
    init_pair(23, COLOR_YELLOW, COLOR_WHITE);
    init_pair(24, COLOR_BLUE, COLOR_WHITE);
    init_pair(25, COLOR_MAGENTA, COLOR_WHITE);
    init_pair(26, COLOR_CYAN, COLOR_WHITE);
    init_pair(27, COLOR_RED, COLOR_BLACK);
    init_pair(28, COLOR_GREEN, COLOR_BLACK);
    init_pair(29, COLOR_YELLOW, COLOR_BLACK);
    init_pair(30, COLOR_BLUE, COLOR_BLACK);
    init_pair(31, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(32, COLOR_CYAN, COLOR_BLACK);
    init_pair(33, COLOR_RED, COLOR_WHITE);
    init_pair(34, COLOR_GREEN, COLOR_WHITE);
    init_pair(35, COLOR_YELLOW, COLOR_WHITE);
    init_pair(36, COLOR_BLUE, COLOR_WHITE);
    init_pair(37, COLOR_MAGENTA, COLOR_WHITE);
    init_pair(38, COLOR_CYAN, COLOR_WHITE);
    init_pair(39, COLOR_RED, COLOR_BLACK);
}

bool ncursesApplications::destroy(bool value)
{
    endwin();
    return value;
}

void ncursesApplications::update()
{
    this->_cpu.updateCpu();
    this->_Ram.updateRam();
    this->_network.updateNetwork();
    this->_tasksMonitor.updateTasks();
}

void ncursesApplications::printMessageOnColorOnWin(WINDOW *win, int color, int x, int y, std::string message)
{
    wattr_on(win, COLOR_PAIR(color), NULL);
    mvwprintw(win, x, y, message.c_str());
    wattr_off(win, COLOR_PAIR(color), NULL);
}

void ncursesApplications::displayUser()
{
    WINDOW *tab =  newwin(8, 67, 0, 0);
    box(tab, 0, 0);
    wbkgd(tab, COLOR_PAIR(5));
    printMessageOnColorOnWin(tab, 4, 0, 10, std::string(" User Informations "));
    printMessageOnColorOnWin(tab, 2, 1, 6, std::string("Username"));
    printMessageOnColorOnWin(tab, 5, 1, 19, "|");
    printMessageOnColorOnWin(tab, 3, 1, 22, this->_user.getUsername());
    printMessageOnColorOnWin(tab, 2, 2, 6, std::string("Hostname"));
    printMessageOnColorOnWin(tab, 5, 2, 19, "|");
    printMessageOnColorOnWin(tab, 3, 2, 22, this->_user.getHostname().size() > 43 ? this->_user.getHostname().substr(0, 20) : this->_user.getHostname());
    printMessageOnColorOnWin(tab, 2, 3, 8, std::string("Date"));
    printMessageOnColorOnWin(tab, 5, 3, 19, "|");
    printMessageOnColorOnWin(tab, 3, 3, 22, this->_dataTimes.getDate());
    printMessageOnColorOnWin(tab, 2, 4, 8, std::string("Time"));
    printMessageOnColorOnWin(tab, 5, 4, 19, "|");
    printMessageOnColorOnWin(tab, 3, 4, 22, this->_dataTimes.getLocaltime());
    printMessageOnColorOnWin(tab, 2, 5, 7, std::string("Uptime"));
    printMessageOnColorOnWin(tab, 5, 5, 19, "|");
    printMessageOnColorOnWin(tab, 3, 5, 22, this->_dataTimes.getUptime());
    printMessageOnColorOnWin(tab, 2, 6, 8, std::string("Zone"));
    printMessageOnColorOnWin(tab, 5, 6, 19, "|");
    printMessageOnColorOnWin(tab, 3, 6, 22, this->_dataTimes.getZone());
    wrefresh(tab);
}

void ncursesApplications::displayKernel()
{
    WINDOW *tab =  newwin(7, 67, 9, 0);
    box(tab, 0, 0);
    wbkgd(tab, COLOR_PAIR(5));
    printMessageOnColorOnWin(tab, 4, 0, 11, std::string(" Kernel version "));
    printMessageOnColorOnWin(tab, 2, 1, 2, std::string(" Kernel version"));
    printMessageOnColorOnWin(tab, 5, 1, 19, std::string("|"));
    printMessageOnColorOnWin(tab, 3, 1, 22, this->_kernel.getKernelVersion().substr(0, 20));
    printMessageOnColorOnWin(tab, 2, 2, 2, std::string("Kernel name (OS)"));
    printMessageOnColorOnWin(tab, 5, 2, 19, "|");
    printMessageOnColorOnWin(tab, 3, 2, 22, this->_kernel.getKernelName());
    printMessageOnColorOnWin(tab, 2, 3, 2, std::string(" Kernel relase"));
    printMessageOnColorOnWin(tab, 5, 3, 19, "|");
    printMessageOnColorOnWin(tab, 3, 3, 22, this->_kernel.getKernelRelease());
    printMessageOnColorOnWin(tab, 2, 4, 2, std::string("Kernel marchine"));
    printMessageOnColorOnWin(tab, 5, 4, 19, "|");
    printMessageOnColorOnWin(tab, 3, 4, 22, this->_kernel.getKernelMachine().size() > 43 ? this->_kernel.getKernelMachine().substr(0, 20) : this->_kernel.getKernelMachine());
    printMessageOnColorOnWin(tab, 2, 5, 2, std::string("Kernel doamaine"));
    printMessageOnColorOnWin(tab, 5, 5, 18, " |");
    printMessageOnColorOnWin(tab, 3, 5, 22, this->_kernel.getKernelDomain());
    wrefresh(tab);
}

void ncursesApplications::displayCpu()
{
    WINDOW *tab =  newwin(this->_cpu.getProcessors().size() + 3, 67, 17, 0);
    box(tab, 0, 0);
    wbkgd(tab, COLOR_PAIR(5));
    printMessageOnColorOnWin(tab, 4, 0, 11, std::string(" CPU Informations "));
    printMessageOnColorOnWin(tab, 2, 1, 5, std::string("CPU model"));
    printMessageOnColorOnWin(tab, 5, 1, 19, std::string("| "));
    printMessageOnColorOnWin(tab, 3, 1, 22, std::string(" ["));
    int value = (int)(this->_cpu.getCpuPercent() / 10);
    int i = 0;
    for (; i <= value; i++) {
        printMessageOnColorOnWin(tab, 39, 1, 24 + i, std::string("|"));
    }
    if (i < 11) {
        for (; i <= 10; i++) {
            printMessageOnColorOnWin(tab, 40, 1, 24 + i, std::string(" "));
        }
    }
    printMessageOnColorOnWin(tab, 3, 1, 24 + i + 1, std::string("]"));
    printMessageOnColorOnWin(tab, 6, 1, 27 + i + 1, (std::to_string(this->_cpu.getCpuPercent()).substr(0, 4) + "%%"));
    std::vector<components::Object *> processors = this->_cpu.getProcessors();
    printMessageOnColorOnWin(tab, 30, 1, 48, (std::to_string(processors.size()) + " processors"));
    for (unsigned int i = 0; i < processors.size(); i++) {
        printMessageOnColorOnWin(tab, 2, 2 + i, 4, std::string("Processor ") + std::to_string(i + 1));
        printMessageOnColorOnWin(tab, 5, 2 + i, 19, std::string("| "));
        printMessageOnColorOnWin(tab, 3, 2 + i, 22, std::string(" ["));
        int value = (this->_cpu.getProcessorPercent(processors[i]) / 10);
        int j = 0;
        for (; j <= value; j++) {
            printMessageOnColorOnWin(tab, 39, 2 + i, 24 + j, std::string("|"));
        }
        if (j < 10) {
            for (; j <= 10; j++) {
                printMessageOnColorOnWin(tab, 39, 2 + i, 24 + j, std::string(" "));
            }
        }
        printMessageOnColorOnWin(tab, 3, 2 + i, 24 + j + 1, std::string("]"));
        printMessageOnColorOnWin(tab, 6, 2 + i, 27 + j + 1, (std::to_string(this->_cpu.getProcessorPercent(processors[i])).substr(0, 4)) + "%%");
        printMessageOnColorOnWin(tab, 7, 2 + i, 48, std::string(processors[i]->getItem("vendor_id")->getData()));
    }

    wrefresh(tab);
}

void ncursesApplications::displayRam()
{
    WINDOW *tab =  newwin(12, 67, 17 + this->_cpu.getProcessors().size() + 4, 0);
    box(tab, 0, 0);
    wbkgd(tab, COLOR_PAIR(5));
    printMessageOnColorOnWin(tab, 4, 0, 11, std::string(" RAM Informations "));
    printMessageOnColorOnWin(tab, 2, 1, 5, std::string("Total RAM"));
    printMessageOnColorOnWin(tab, 5, 1, 19, std::string("| "));
    printMessageOnColorOnWin(tab, 3, 1, 27, std::string(std::to_string(std::stof(this->_Ram.getTotalRam()->getData()) / 1000000).substr(0, 4) + " GB"));
    printMessageOnColorOnWin(tab, 2, 2, 5, std::string("Used RAM"));
    printMessageOnColorOnWin(tab, 5, 2, 19, std::string("| "));
    printMessageOnColorOnWin(tab, 3, 2, 22, std::string(" ["));
    float value = (std::stof(this->_Ram.getUsedRam()->getData()) / 1000);
    int i = 0;
    for (; i <= value; i++) {
        printMessageOnColorOnWin(tab, 39, 2, 24 + i, std::string("|"));
    }
    if (i < 11) {
        for (; i <= 10; i++) {
            printMessageOnColorOnWin(tab, 40, 2, 24 + i, std::string(" "));
        }
    }
    printMessageOnColorOnWin(tab, 3, 2, 24 + i + 1, std::string("]"));
    printMessageOnColorOnWin(tab, 6, 2, 27 + i + 1, (std::to_string(std::stof(this->_Ram.getUsedRam()->getData()) / 1000).substr(0, 4) + " GB"));
    printMessageOnColorOnWin(tab, 1, 2, 47, "/ " + std::string(std::to_string(std::stof(this->_Ram.getTotalRam()->getData()) / 1000000).substr(0, 4) + " GB"));
    printMessageOnColorOnWin(tab, 2, 3, 5, std::string("Free RAM"));
    printMessageOnColorOnWin(tab, 5, 3, 19, std::string("| "));
    printMessageOnColorOnWin(tab, 3, 3, 22, std::string(" ["));
    value = (std::stof(this->_Ram.getFreeRam()->getData()) / 1000000);
    i = 0;
    for (; i <= value; i++) {
        printMessageOnColorOnWin(tab, 39, 3, 24 + i, std::string("|"));
    }
    if (i < 11) {
        for (; i <= 10; i++) {
            printMessageOnColorOnWin(tab, 40, 3, 24 + i, std::string(" "));
        }
    }
    printMessageOnColorOnWin(tab, 3, 3, 24 + i + 1, std::string("]"));
    printMessageOnColorOnWin(tab, 6, 3, 27 + i + 1, (std::to_string(std::stof(this->_Ram.getFreeRam()->getData()) / 1000000).substr(0, 4) + " GB"));
    printMessageOnColorOnWin(tab, 1, 3, 47, "/ " + std::string(std::to_string(std::stof(this->_Ram.getTotalRam()->getData()) / 1000000).substr(0, 4) + " GB"));
    printMessageOnColorOnWin(tab, 2, 4, 5, std::string("Shared RAM"));
    printMessageOnColorOnWin(tab, 5, 4, 19, std::string("| "));
    printMessageOnColorOnWin(tab, 3, 4, 22, std::string(" ["));
    value = (std::stof(this->_Ram.getSharedRam()->getData()) / 1000000);
    i = 0;
    for (; i <= value; i++) {
        printMessageOnColorOnWin(tab, 39, 4, 24 + i, std::string("|"));
    }
    if (i < 11) {
        for (; i <= 10; i++) {
            printMessageOnColorOnWin(tab, 40, 4, 24 + i, std::string(" "));
        }
    }
    printMessageOnColorOnWin(tab, 3, 4, 24 + i + 1, std::string("]"));
    printMessageOnColorOnWin(tab, 6, 4, 27 + i + 1, (std::to_string(std::stof(this->_Ram.getSharedRam()->getData()) / 1000000).substr(0, 4) + " GB"));
    printMessageOnColorOnWin(tab, 1, 4, 47, "/ " + std::string(std::to_string(std::stof(this->_Ram.getTotalRam()->getData()) / 1000000).substr(0, 4) + " GB"));
    printMessageOnColorOnWin(tab, 2, 5, 5, std::string("Buffer RAM"));
    printMessageOnColorOnWin(tab, 5, 5, 19, std::string("| "));
    printMessageOnColorOnWin(tab, 3, 5, 22, std::string(" ["));
    value = (std::stof(this->_Ram.getBufferRam()->getData()) / 1000000);
    i = 0;
    for (; i <= value; i++) {
        printMessageOnColorOnWin(tab, 39, 5, 24 + i, std::string("|"));
    }
    if (i < 11) {
        for (; i <= 10; i++) {
            printMessageOnColorOnWin(tab, 40, 5, 24 + i, std::string(" "));
        }
    }
    printMessageOnColorOnWin(tab, 3, 5, 24 + i + 1, std::string("]"));
    printMessageOnColorOnWin(tab, 6, 5, 27 + i + 1, (std::to_string(std::stof(this->_Ram.getBufferRam()->getData()) / 1000000).substr(0, 4) + " GB"));
    printMessageOnColorOnWin(tab, 1, 5, 47, "/ " + std::string(std::to_string(std::stof(this->_Ram.getTotalRam()->getData()) / 1000000).substr(0, 4) + " GB"));
    printMessageOnColorOnWin(tab, 2, 6, 5, std::string("Cached RAM"));
    printMessageOnColorOnWin(tab, 5, 6, 19, std::string("| "));
    printMessageOnColorOnWin(tab, 3, 6, 22, std::string(" ["));
    value = (std::stof(this->_Ram.getCacheRam()->getData()) / 1000000);
    i = 0;
    for (; i <= value; i++) {
        printMessageOnColorOnWin(tab, 39, 6, 24 + i, std::string("|"));
    }
    if (i < 11) {
        for (; i <= 10; i++) {
            printMessageOnColorOnWin(tab, 40, 6, 24 + i, std::string(" "));
        }
    }
    printMessageOnColorOnWin(tab, 3, 6, 24 + i + 1, std::string("]"));
    printMessageOnColorOnWin(tab, 6, 6, 27 + i + 1, (std::to_string(std::stof(this->_Ram.getCacheRam()->getData()) / 1000000).substr(0, 4) + " GB"));
    printMessageOnColorOnWin(tab, 1, 6, 47, "/ " + std::string(std::to_string(std::stof(this->_Ram.getTotalRam()->getData()) / 1000000).substr(0, 4) + " GB"));
    
    printMessageOnColorOnWin(tab, 2, 8, 5, std::string("Swap Total"));
    printMessageOnColorOnWin(tab, 5, 8, 19, std::string("| "));
    printMessageOnColorOnWin(tab, 3, 8, 27, (std::to_string(std::stof(this->_Ram.getSwapTotal()->getData()) / 1000000).substr(0, 4) + " GB"));
    printMessageOnColorOnWin(tab, 2, 9, 5, std::string("Swap Free"));
    printMessageOnColorOnWin(tab, 5, 9, 19, std::string("| "));
    printMessageOnColorOnWin(tab, 3, 9, 22, std::string(" ["));
    value = (std::stof(this->_Ram.getSwapFree()->getData()) / 1000000) * 10 / (std::stof(this->_Ram.getSwapTotal()->getData()) / 1000000);
    i = 0;
    for (; i <= value; i++) {
        printMessageOnColorOnWin(tab, 39, 9, 24 + i, std::string("|"));
    }
    if (i < 11) {
        for (; i <= 10; i++) {
            printMessageOnColorOnWin(tab, 40, 9, 24 + i, std::string(" "));
        }
    }
    printMessageOnColorOnWin(tab, 3, 9, 24 + i + 1, std::string("]"));
    printMessageOnColorOnWin(tab, 6, 9, 27 + i + 1, (std::to_string(std::stof(this->_Ram.getSwapFree()->getData()) / 1000000).substr(0, 4) + " GB"));
    printMessageOnColorOnWin(tab, 1, 9, 47, "/ " + std::string(std::to_string(std::stof(this->_Ram.getSwapTotal()->getData()) / 1000000).substr(0, 4) + " GB"));
    printMessageOnColorOnWin(tab, 2, 10, 5, std::string("Swap Used"));
    printMessageOnColorOnWin(tab, 5, 10, 19, std::string("| "));
    printMessageOnColorOnWin(tab, 3, 10, 22, std::string(" ["));
    value = (std::stof(this->_Ram.getSwapTotal()->getData()) - std::stof(this->_Ram.getSwapFree()->getData())) / 1000000;
    i = 0;
    for (; i <= value; i++) {
        printMessageOnColorOnWin(tab, 39, 10, 24 + i, std::string("|"));
    }
    if (i < 11) {
        for (; i <= 10; i++) {
            printMessageOnColorOnWin(tab, 40, 10, 24 + i, std::string(" "));
        }
    }
    printMessageOnColorOnWin(tab, 3, 10, 24 + i + 1, std::string("]"));
    printMessageOnColorOnWin(tab, 6, 10, 27 + i + 1, (std::to_string(value).substr(0, 4) + " GB"));
    printMessageOnColorOnWin(tab, 1, 10, 47, "/ " + std::string(std::to_string(std::stof(this->_Ram.getSwapTotal()->getData()) / 1000000).substr(0, 4) + " GB"));
    
    
    wrefresh(tab);
}

void ncursesApplications::displayNetwork()
{
    std::vector<components::Object *> data = this->_network.getNetworkAllInfo();
    WINDOW *tab = newwin(data.size() + 4, 200, 17 + this->_cpu.getProcessors().size() + 5 + 12, 0);
    box(tab, 0, 0);
    wbkgd(tab, COLOR_PAIR(5));
    printMessageOnColorOnWin(tab, 4, 0, 15, std::string(" Network "));
    printMessageOnColorOnWin(tab, 14, 0, 56, std::string(" Receive "));
    printMessageOnColorOnWin(tab, 14, 0, 141, std::string(" Transmit "));

    printMessageOnColorOnWin(tab, 2, 1, 8, std::string("Name"));
    printMessageOnColorOnWin(tab, 0, 1, 19, std::string("| "));
    printMessageOnColorOnWin(tab, 2, 1, 23, std::string("Bytes"));
    printMessageOnColorOnWin(tab, 0, 1, 30, std::string("| "));
    printMessageOnColorOnWin(tab, 2, 1, 32, std::string("Packets"));
    printMessageOnColorOnWin(tab, 0, 1, 40, std::string("| "));
    printMessageOnColorOnWin(tab, 2, 1, 42, std::string("Errors"));
    printMessageOnColorOnWin(tab, 0, 1, 49, std::string("| "));
    printMessageOnColorOnWin(tab, 2, 1, 51, std::string("Drops"));
    printMessageOnColorOnWin(tab, 0, 1, 57, std::string("| "));
    printMessageOnColorOnWin(tab, 2, 1, 59, std::string("Fifo"));
    printMessageOnColorOnWin(tab, 0, 1, 64, std::string("| "));
    printMessageOnColorOnWin(tab, 2, 1, 67, std::string("Frame"));
    printMessageOnColorOnWin(tab, 0, 1, 73, std::string("| "));
    printMessageOnColorOnWin(tab, 2, 1, 75, std::string("Compressed"));
    printMessageOnColorOnWin(tab, 0, 1, 86, std::string("| "));
    printMessageOnColorOnWin(tab, 2, 1, 90, std::string("Multicast"));
    printMessageOnColorOnWin(tab, 4, 1, 103, std::string("| "));

    printMessageOnColorOnWin(tab, 2, 1, 107, std::string("Bytes"));
    printMessageOnColorOnWin(tab, 0, 1, 115, std::string("| "));
    printMessageOnColorOnWin(tab, 2, 1, 117, std::string("Packets"));
    printMessageOnColorOnWin(tab, 0, 1, 125, std::string("| "));
    printMessageOnColorOnWin(tab, 2, 1, 127, std::string("Errors"));
    printMessageOnColorOnWin(tab, 0, 1, 134, std::string("| "));
    printMessageOnColorOnWin(tab, 2, 1, 136, std::string("Drops"));
    printMessageOnColorOnWin(tab, 0, 1, 142, std::string("| "));
    printMessageOnColorOnWin(tab, 2, 1, 144, std::string("Fifo"));
    printMessageOnColorOnWin(tab, 0, 1, 149, std::string("| "));
    printMessageOnColorOnWin(tab, 2, 1, 151, std::string("Frame"));
    printMessageOnColorOnWin(tab, 0, 1, 157, std::string("| "));
    printMessageOnColorOnWin(tab, 2, 1, 159, std::string("Compressed"));
    printMessageOnColorOnWin(tab, 0, 1, 170, std::string("| "));
    printMessageOnColorOnWin(tab, 2, 1, 173, std::string("Multicast"));
    printMessageOnColorOnWin(tab, 4, 1, 183, std::string("| "));
    printMessageOnColorOnWin(tab, 2, 1, 188, "RX / TX");


    printMessageOnColorOnWin(tab, 0, 2, 2, "----------------");
    printMessageOnColorOnWin(tab, 0, 2, 19, "|");
    printMessageOnColorOnWin(tab, 0, 2, 21, "----------------");
    printMessageOnColorOnWin(tab, 0, 2, 30, "|");
    printMessageOnColorOnWin(tab, 0, 2, 31, "----------------");
    printMessageOnColorOnWin(tab, 0, 2, 40, "|");
    printMessageOnColorOnWin(tab, 0, 2, 41, "----------------");
    printMessageOnColorOnWin(tab, 0, 2, 49, "|");
    printMessageOnColorOnWin(tab, 0, 2, 51, "----------------");
    printMessageOnColorOnWin(tab, 0, 2, 64, "|");
    printMessageOnColorOnWin(tab, 0, 2, 65, "----------------");
    printMessageOnColorOnWin(tab, 0, 2, 73, "|");
    printMessageOnColorOnWin(tab, 0, 2, 75, "----------------");
    printMessageOnColorOnWin(tab, 0, 2, 86, "|");
    printMessageOnColorOnWin(tab, 0, 2, 87, "---------------");
    printMessageOnColorOnWin(tab, 4, 2, 103, "|");
    printMessageOnColorOnWin(tab, 0, 2, 105, "---------------");
    printMessageOnColorOnWin(tab, 0, 2, 115, "|");
    printMessageOnColorOnWin(tab, 0, 2, 117, "----------------");
    printMessageOnColorOnWin(tab, 0, 2, 125, "|");
    printMessageOnColorOnWin(tab, 0, 2, 127, "----------------");
    printMessageOnColorOnWin(tab, 0, 2, 134, "|");
    printMessageOnColorOnWin(tab, 0, 2, 136, "----------------");
    printMessageOnColorOnWin(tab, 0, 2, 142, "|");
    printMessageOnColorOnWin(tab, 0, 2, 144, "----------------");
    printMessageOnColorOnWin(tab, 0, 2, 149, "|");
    printMessageOnColorOnWin(tab, 0, 2, 151, "----------------");
    printMessageOnColorOnWin(tab, 0, 2, 157, "|");
    printMessageOnColorOnWin(tab, 0, 2, 159, "----------------");
    printMessageOnColorOnWin(tab, 0, 2, 170, "|");
    printMessageOnColorOnWin(tab, 0, 2, 172, "------------");
    printMessageOnColorOnWin(tab, 4, 2, 183, "|");
    printMessageOnColorOnWin(tab, 0, 2, 185, "--------------");
    for (unsigned int i = 0; i < data.size(); i++) {
        std::string name = data[i]->getId();
        printMessageOnColorOnWin(tab, 2, 3 + i, 7, name);
        printMessageOnColorOnWin(tab, 0, 3 + i, 19, std::string("| "));
        std::vector<components::Item *> values = data[i]->getItems();
        printMessageOnColorOnWin(tab, 3, 3 + i, 23, values[1]->getData());
        printMessageOnColorOnWin(tab, 0, 3 + i, 30, std::string("| "));
        printMessageOnColorOnWin(tab, 3, 3 + i, 35, values[2]->getData());
        printMessageOnColorOnWin(tab, 0, 3 + i, 40, std::string("| "));
        printMessageOnColorOnWin(tab, 3, 3 + i, 44, values[3]->getData());
        printMessageOnColorOnWin(tab, 0, 3 + i, 49, std::string("| "));
        printMessageOnColorOnWin(tab, 3, 3 + i, 53, values[4]->getData());
        printMessageOnColorOnWin(tab, 0, 3 + i, 64, std::string("| "));
        printMessageOnColorOnWin(tab, 3, 3 + i, 67, values[5]->getData());
        printMessageOnColorOnWin(tab, 0, 3 + i, 73, std::string("| "));
        printMessageOnColorOnWin(tab, 3, 3 + i, 80  , values[6]->getData());
        printMessageOnColorOnWin(tab, 0, 3 + i, 86, std::string("| "));
        printMessageOnColorOnWin(tab, 3, 3 + i, 94, values[7]->getData());
        printMessageOnColorOnWin(tab, 4, 3 + i, 103, std::string("| "));
        printMessageOnColorOnWin(tab, 3, 3 + i, 106, values[8]->getData());
        printMessageOnColorOnWin(tab, 0, 3 + i, 115, std::string("| "));
        printMessageOnColorOnWin(tab, 3, 3 + i, 118, values[9]->getData());
        printMessageOnColorOnWin(tab, 0, 3 + i, 125, std::string("| "));
        printMessageOnColorOnWin(tab, 3, 3 + i, 129, values[10]->getData());
        printMessageOnColorOnWin(tab, 0, 3 + i, 134, std::string("| "));
        printMessageOnColorOnWin(tab, 3, 3 + i, 137, values[11]->getData());
        printMessageOnColorOnWin(tab, 0, 3 + i, 142, std::string("| "));
        printMessageOnColorOnWin(tab, 3, 3 + i, 145, values[12]->getData());
        printMessageOnColorOnWin(tab, 0, 3 + i, 149, std::string("| "));
        printMessageOnColorOnWin(tab, 3, 3 + i, 153, values[13]->getData());
        printMessageOnColorOnWin(tab, 0, 3 + i, 157, std::string("| "));
        printMessageOnColorOnWin(tab, 3, 3 + i, 163, values[14]->getData());
        printMessageOnColorOnWin(tab, 0, 3 + i, 170, std::string("| "));
        printMessageOnColorOnWin(tab, 3, 3 + i, 176, values[15]->getData());
        printMessageOnColorOnWin(tab, 4, 3 + i, 183, std::string("| "));
        printMessageOnColorOnWin(tab, 0, 3 + i, 57, std::string("| "));
        printMessageOnColorOnWin(tab, 3, 3 + i, 188, std::to_string( std::stoi(values[1]->getData()) + std::stoi(values[2]->getData()) + std::stoi(values[3]->getData()) + std::stoi(values[4]->getData()) + std::stoi(values[5]->getData()) + std::stoi(values[6]->getData()) + std::stoi(values[7]->getData()) + std::stoi(values[8]->getData()) + std::stoi(values[9]->getData()) + std::stoi(values[10]->getData()) + std::stoi(values[11]->getData()) + std::stoi(values[12]->getData()) + std::stoi(values[13]->getData()) + std::stoi(values[14]->getData()) + std::stoi(values[15]->getData())  ));
    }

    wrefresh(tab);
}

void ncursesApplications::displayTasks()
{
    WINDOW *tab = newwin(45, 130, 0, 70);
    box(tab, 0, 0);
    printMessageOnColorOnWin(tab, 30, 0, 62, " Tasks ");
    printMessageOnColorOnWin(tab, 0, 1, 4, " Tasks:    " + std::to_string(this->_tasksMonitor.count()) + "     Running:   " + std::to_string(this->_tasksMonitor.getOnly("running").size()));
    printMessageOnColorOnWin(tab, 0, 2, 4, "Sleeping:  " + std::to_string(this->_tasksMonitor.getOnly("sleeping").size()) + "       Idle:   " + std::to_string(this->_tasksMonitor.getOnly("idle").size()));

    printMessageOnColorOnWin(tab, rand() % 36, 2, 80, "PRESS C TO CHANGE ON GRAPHICAL MODE");
    printMessageOnColorOnWin(tab, 5, 4, 4, "PID");
    printMessageOnColorOnWin(tab, 5, 4, 20, "NAME");
    printMessageOnColorOnWin(tab, 5, 4, 41, "STATE");
    printMessageOnColorOnWin(tab, 5, 4, 49, "FDSize");
    printMessageOnColorOnWin(tab, 5, 4, 58, "Cpu Usage");
    printMessageOnColorOnWin(tab, 5, 4, 69, "Priority");
    printMessageOnColorOnWin(tab, 5, 4, 95, "COMMAND");

    std::vector<IMonitorModule::Tasks::TaskItem *> data = this->_tasksMonitor.getTasks();
    if (this->_key == 's') {
        this->_starter_tasks += 1;
        if (this->_starter_tasks + 37 >= data.size()) {
            this->_starter_tasks = data.size() - 37;
        }
    }
    if (this->_key == 'z') {
        this->_starter_tasks -= 1;
        if (this->_starter_tasks < 0) {
            this->_starter_tasks = 0;
        }
    }
    int i = 0;
    for (unsigned int j = this->_starter_tasks; j < this->_starter_tasks + 37; j++) {
        if (j >= data.size()) {
            break;
        }
        printMessageOnColorOnWin(tab, 11, 6 + i, 4, std::to_string(data[j]->getPid()));
        std::vector<components::Item *> got = data[j]->getFile("status")->getItems();
        for (unsigned int k = 0; k < got.size(); k++) {
            std::string name = got[k]->getName();
            std::string datas = got[k]->getData();
            if (name == "Name") {
                printMessageOnColorOnWin(tab, 0, 6 + i, 10, datas.replace(0, 1, ""));
            }
            if (name == "State") {
                if (datas.find("S") != std::string::npos) {
                    printMessageOnColorOnWin(tab, 6, 6 + i, 40, "Sleeping");
                } else if (datas.find("R") != std::string::npos) {
                    printMessageOnColorOnWin(tab, 3, 6 + i, 40, "Running");
                } else if (datas.find("I") != std::string::npos) {
                    printMessageOnColorOnWin(tab, 2, 6 + i, 40, "Idle");
                } else if (datas.find("Z") != std::string::npos) {
                    printMessageOnColorOnWin(tab, 4, 6 + i, 40, "Zombie");
                } else if (datas.find("T") != std::string::npos) {
                    printMessageOnColorOnWin(tab, 4, 6 + i, 40, "Stopped");
                } else if (datas.find("W") != std::string::npos) {
                    printMessageOnColorOnWin(tab, 4, 6 + i, 40, "Paging");
                } else if (datas.find("X") != std::string::npos) {
                    printMessageOnColorOnWin(tab, 4, 6 + i, 40, "Dead");
                } else if (datas.find("x") != std::string::npos) {
                    printMessageOnColorOnWin(tab, 4, 6 + i, 40, "Dead");
                } else if (datas.find("K") != std::string::npos) {
                    printMessageOnColorOnWin(tab, 4, 6 + i, 40, "Wakekill");
                } else if (datas.find("P") != std::string::npos) {
                    printMessageOnColorOnWin(tab, 4, 6 + i, 40, "Parked");
                } else if (datas.find("D") != std::string::npos) {
                    printMessageOnColorOnWin(tab, 4, 6 + i, 40, "Waiting");
                } else if (datas.find("L") != std::string::npos) {
                    printMessageOnColorOnWin(tab, 4, 6 + i, 40, "Locked");
                } else if (datas.find("s") != std::string::npos) {
                    printMessageOnColorOnWin(tab, 4, 6 + i, 40, "Session");
                } else {
                    printMessageOnColorOnWin(tab, 0, 6 + i, 40, datas);
                }
            }
            if (name == "voluntary_ctxt_switches") {
                int tmp = std::stoi(datas.replace(0, 1, ""));
                if (tmp < 100)
                    printMessageOnColorOnWin(tab, 1, 6 + i, 50, datas);
                else if (tmp < 1000)
                    printMessageOnColorOnWin(tab, 2, 6 + i, 50, datas);
                else if (tmp < 10000)
                    printMessageOnColorOnWin(tab, 3, 6 + i, 50, datas);
                else if (tmp < 100000)
                    printMessageOnColorOnWin(tab, 4, 6 + i, 50, datas);
                else if (tmp < 1000000)
                    printMessageOnColorOnWin(tab, 5, 6 + i, 50, datas);
                else if (tmp < 10000000)
                    printMessageOnColorOnWin(tab, 6, 6 + i, 50, datas);
                else if (tmp < 100000000)
                    printMessageOnColorOnWin(tab, 7, 6 + i, 50, datas);
                else if (tmp < 1000000000)
                    printMessageOnColorOnWin(tab, 8, 6 + i, 50, datas);
                else
                    printMessageOnColorOnWin(tab, 0, 6 + i, 50, datas); 
            }
            if (name == "Cpus_allowed_list") {
                std::string tmp = datas.replace(0, 1, "");
                if (tmp[0] == '0')
                    printMessageOnColorOnWin(tab, 1, 6 + i, 60, tmp);
                else if (tmp[0] == '1')
                    printMessageOnColorOnWin(tab, 2, 6 + i, 60, tmp);
                else if (tmp[0] == '2')
                    printMessageOnColorOnWin(tab, 3, 6 + i, 60, tmp);
                else if (tmp[0] == '3')
                    printMessageOnColorOnWin(tab, 4, 6 + i, 60, tmp);
                else if (tmp[0] == '4')
                    printMessageOnColorOnWin(tab, 5, 6 + i, 60, tmp);
                else if (tmp[0] == '5')
                    printMessageOnColorOnWin(tab, 6, 6 + i, 60, tmp);
                else if (tmp[0] == '6')
                    printMessageOnColorOnWin(tab, 7, 6 + i, 60, tmp);
                else if (tmp[0] == '7')
                    printMessageOnColorOnWin(tab, 8, 6 + i, 60, tmp);
                else if (tmp[0] == '8')
                    printMessageOnColorOnWin(tab, 9, 6 + i, 60, tmp);
                else
                    printMessageOnColorOnWin(tab, 0, 6 + i, 60, tmp);
            }
            if (name == "SigQ") {
                std::string tmp = datas.replace(0, 1, "");
                if (tmp[0] == '1')
                    printMessageOnColorOnWin(tab, 3, 6 + i, 70, tmp);
                else if (tmp[0] == '2')
                    printMessageOnColorOnWin(tab, 2, 6 + i, 70, tmp);
                else if (tmp[0] == '3')
                    printMessageOnColorOnWin(tab, 3, 6 + i, 70, tmp);
                else if (tmp[0] == '4')
                    printMessageOnColorOnWin(tab, 4, 6 + i, 70, tmp);
                else if (tmp[0] == '5')
                    printMessageOnColorOnWin(tab, 5, 6 + i, 70, tmp);
                else if (tmp[0] == '6')
                    printMessageOnColorOnWin(tab, 6, 6 + i, 70, tmp);
                else if (tmp[0] == '7')
                    printMessageOnColorOnWin(tab, 7, 6 + i, 70, tmp);
                else if (tmp[0] == '8')
                    printMessageOnColorOnWin(tab, 8, 6 + i, 70, tmp);
                else if (tmp[0] == '9')
                    printMessageOnColorOnWin(tab, 9, 6 + i, 70, tmp);
                else
                    printMessageOnColorOnWin(tab, 15, 6 + i, 70, tmp);
            }

            printMessageOnColorOnWin(tab, 7, 6 + i, 80, data[j]->getFile("cmdline")->getItem("cmdline")->getData().substr(0, 49));
        }
        i++;
    }
    data.clear();
    wrefresh(tab);
}

void ncursesApplications::display()
{
    this->_key = getch();

    this->displayUser();
    this->displayKernel();
    this->displayCpu();
    this->displayRam();
    this->displayNetwork();
    this->displayTasks();
    refresh();
    usleep(50000);
    if (this->_key == 'c' || this->_key == 'C') {
        this->_isRunning = false;
        this->_switch = true;
    }
}
