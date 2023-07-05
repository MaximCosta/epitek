/*
** EPITECH PROJECT, 2023
** Visual Studio Live Share (Espace de travail)
** File description:
** tasks
*/

#include "../../include/core/core.hpp"
#include "../../include/lib/utils.hpp"

namespace IMonitorModule
{

    namespace Tasks
    {
        std::vector<TaskItem *> TasksMonitor::getTasks() const { return this->_tasks; }
        void TasksMonitor::clearTasks() {
            for (unsigned int i = 0; i < this->_tasks.size(); i++)
                this->_tasks[i]->clearFiles();
            this->_tasks.clear();
        }

        std::vector<TaskItem *> TasksMonitor::getOnly(std::string filter) const
        {
            std::vector<TaskItem *> allTasks = this->getTasks();
            std::vector<TaskItem *> runningTasks;
            for (unsigned int i = 0; i < allTasks.size(); i++) {
                components::Object *statusFile = allTasks[i]->getFile("status");
                if (!statusFile) continue;
                std::string state = statusFile->getItem("State")->getData();
                if (state.find(filter) != std::string::npos)
                    runningTasks.push_back(allTasks[i]);
            }
            return runningTasks;
        }

        int TasksMonitor::count() const { return this->_tasks.size(); }
        void TasksMonitor::updateTasks() {
            this->clearTasks();
            DIR *dir = opendir("/proc");
            struct dirent *ent;
            if (!dir) return;

            while ((ent = readdir(dir))) {
                if (ent->d_name[0] >= '0' && ent->d_name[0] <= '9') {
                    int pid = std::stoi(ent->d_name);
                    TaskItem *task = new TaskItem(pid);
                    task->updateTaskItem();
                    this->_tasks.push_back(task);
                }
            }
            closedir(dir);
        }

        TaskItem::TaskItem(int pid) { this->_pid = pid; }

        void TaskItem::clearFiles() {
            for (unsigned int i = 0; i < this->_files.size(); i++)
                delete this->_files[i];
            this->_files.clear();
        }

        std::vector<components::Object *> TaskItem::getFiles() const { return this->_files; };
        void TaskItem::addFileContent(const std::string &path, const std::string name) {
            std::ifstream file(path);
            std::string line;

            components::Object *fileObject = new components::Object();
            fileObject->setId(name);
            if (file.is_open()) {
                while (std::getline(file, line)) {
                    std::string name = line.substr(0, line.find(":"));
                    std::string value = line.substr(line.find(":") + 1, line.size());
                    name = remove_trailing_space_before(name);
                    value = remove_trailing_space_after(value);
                    fileObject->addItem(name, value);
                }
                file.close();
            }
            this->_files.push_back(fileObject);
        }

        void TaskItem::addFileString(const std::string &path, const std::string name) {
            std::ifstream file(path);
            std::string line;

            components::Object *fileObject = new components::Object();
            fileObject->setId(name);
            if (file.is_open()) {
                while (std::getline(file, line))
                    fileObject->addItem(name, line);
                file.close();
            }
            this->_files.push_back(fileObject);
        }

        components::Object *TaskItem::getFile(const std::string &name) const {

            for (unsigned int i = 0; i < this->_files.size(); i++) {
                if (this->_files[i]->getId() == name)
                    return this->_files[i];
            }
            return nullptr;
        }

        void TaskItem::updateTaskItem() {
            this->clearFiles();

            std::string path = "/proc/" + std::to_string(this->_pid);
            DIR *dir = opendir(path.c_str());
            struct dirent *ent;
            if (!dir) return;

            while ((ent = readdir(dir))) {
                std::string filename(ent->d_name);
                if (filename == "status")
                    this->addFileContent(path + "/status", "status");
                if (filename == "cmdline")
                    this->addFileString(path + "/cmdline", "cmdline");
            }
            closedir(dir);
        }
        int TaskItem::getPid() const { return this->_pid; }

    } // namespace Tasks



} // namespace IMonitorModule
