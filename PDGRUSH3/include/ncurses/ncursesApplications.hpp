/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGRUSH3-nathan.catalan
** File description:
** ncursesApplications
*/

#ifndef NCURSESAPPLICATIONS_HPP_
    #define NCURSESAPPLICATIONS_HPP_
    #include "../../include/core/core.hpp"
    #include "../../include/lib/object.hpp"


class ncursesApplications {
    public:
        ncursesApplications();
        ~ncursesApplications();

        void printMessageOnColorOnWin(WINDOW *win, int color, int x, int y, std::string message);
        bool isRunning() const;
        void init(); // init ncurses
        bool destroy(bool value); // destroy ncurses
        void update(); // update all data
        void display(); // display all data
        void displayUser(); // display user data
        void displayKernel(); // display kernel data
        void displayCpu(); // display cpu data
        void displayRam(); // display ram data
        void displayNetwork(); // display network data
        void displayTasks(); // display tasks data
        bool _switch;
    
    private:
        IMonitorModule::Kernel _kernel;
        IMonitorModule::DataTimes _dataTimes;
        IMonitorModule::User _user;
        IMonitorModule::Cpu _cpu;
        IMonitorModule::Ram _Ram;
        IMonitorModule::Tasks::TasksMonitor _tasksMonitor;
        IMonitorModule::Network _network;
        bool _isRunning;
        int _starter_tasks;
        char _key;
};

#endif /* !NCURSESAPPLICATIONS_HPP_ */
