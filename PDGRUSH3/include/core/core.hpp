/*
** EPITECH PROJECT, 2023
** Visual Studio Live Share (Espace de travail)
** File description:
** core
*/

#ifndef CORE_HPP_
    #define CORE_HPP_
    #include <iostream>
    #include <ncurses.h>
    #undef scroll
    #include <unistd.h>
    #include <iostream>
    #include <unistd.h>
    #include <time.h>
    #include <fstream>
    #include <sstream>
    #include <string>
    #include <sys/utsname.h>
    #include "../lib/object.hpp"
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <dirent.h>


namespace IMonitorModule
{
    class Kernel {
        public:
            std::string getKernelVersion() const;
            std::string getKernelName() const;
            std::string getKernelDomain() const;
            std::string getKernelMachine() const;
            std::string getKernelRelease() const;
    };

    class DataTimes {
        public:
            std::string getLocaltime() const;
            std::string getDate() const;
            std::string getUptime() const;
            std::string getZone() const;
    };

    class User {
        public:
            std::string getHostname() const;
            std::string getUsername() const;
    };

    class Cpu {
        public:
            Cpu();
            ~Cpu() {};

            void updateCpu();
            void clearProcessors();
            double getCpuPercent() const;

            template <typename T>
            T convertTo(const std::string &str) const;

            components::Object *getCpuInfo() const;
            std::vector<components::Object *> getProcessors() const;
            double getProcessorPercent(const components::Object *processor) const;

        private:
            void updateProcessors();

            components::Object *_cpuinfo;
            std::vector<components::Object *> _processors;
    };

    class Ram {
        public:
            Ram();
            ~Ram();

            void updateRam();
            components::Item *getTotalRam() const;
            components::Item *getFreeRam() const;
            components::Item *getUsedRam() const;
            components::Item *getSharedRam() const;
            components::Item *getBufferRam() const;
            components::Item *getCacheRam() const;
            components::Item *getAvailableRam() const;
            components::Item *getSwapTotal() const;
            components::Item *getSwapFree() const;
            components::Item *getSwapUsed() const;

        private:
            components::Object *_raminfo;
    };

    namespace Tasks
    {
        class TaskItem {
            public:
                TaskItem(int pid);
                ~TaskItem() {};

                void updateTaskItem();
                void clearFiles();
                int getPid() const;
                std::vector<components::Object *> getFiles() const;
                components::Object *getFile(const std::string &name) const;

            private:
                void addFileContent(const std::string &path, const std::string name);
                void addFileString(const std::string &path, const std::string name);

                int _pid;
                std::vector<components::Object *> _files;
        };

        class TasksMonitor {
            public:
                TasksMonitor() {};
                ~TasksMonitor() {};

                void updateTasks();
                void clearTasks();
                int count() const;
                std::vector<TaskItem *> getOnly(std::string filter) const;
                std::vector<TaskItem *> getTasks() const;

            private:
                std::vector<TaskItem *> _tasks;
        };
    };

    class Network {
        public:
            Network();
            ~Network();

            void updateNetwork();
            std::vector<components::Object *> getNetworkAllInfo() const;

        private:
            std::vector<components::Object *> _networkinfo;
    };
};


#endif /* !CORE_HPP_ */
