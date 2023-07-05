#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <string>
#include <math.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->_kernel = new IMonitorModule::Kernel();
    this->_dataTimes = new IMonitorModule::DataTimes();
    this->_user = new IMonitorModule::User();
    this->_cpu = new IMonitorModule::Cpu();
    this->_ram = new IMonitorModule::Ram();
    this->_network = new IMonitorModule::Network();
    this->_tasksMonitor = new IMonitorModule::Tasks::TasksMonitor();

    this->_cpu->updateCpu();
    QLabel *label = findChild<QLabel*>("nbProcessors");
    int nb = this->_cpu->getProcessors().size();
    label->setText(QString::fromStdString(std::to_string(nb)));

    int y = 40;
    int x = 240;
    for (int i = 0; i < nb; i++) {
        std::string name = "bar" + std::to_string(i + 1);
        std::string color = "#935DFE;";
        this->createBar(name, x, y, color);
        y += 60;
        if (i == 2 || i == 5 || i == 8) {
            y = 40;
            x += 250;
        }
    }

    ui->userName->setText(QString::fromStdString(this->_user->getUsername()));
    ui->Hostname->setText(QString::fromStdString(this->_user->getHostname()));
    ui->zone->setText(QString::fromStdString(this->_dataTimes->getZone()));
    ui->KERNEL_VERSION->setText(QString::fromStdString(this->_kernel->getKernelVersion()));
    ui->KERNA_NAME->setText(QString::fromStdString(this->_kernel->getKernelName()));
    ui->KERNEL_RELEASE->setText(QString::fromStdString(this->_kernel->getKernelRelease()));
    ui->KERNEL_MACHINE->setText(QString::fromStdString(this->_kernel->getKernelMachine()));
    ui->KERNEL_DOMAINE->setText(QString::fromStdString(this->_kernel->getKernelDomain()));
    ui->ProcessorsModule->setStyleSheet("color:white;background-color: #FAA069;");
    ui->KernelModule->setStyleSheet("color:white;background-color: #FAA069;");
    ui->UserModule->setStyleSheet("color:white;background-color: #FAA069;");
    ui->CPUModule->setStyleSheet("color:white;background-color: #FAA069;");
    ui->TasksManagerModule->setStyleSheet("color:white;background-color: #FAA069;");
    ui->RAMModule->setStyleSheet("color:white;background-color: #FAA069;");

    // GET FRAME WITH NAME
    this->addHover("Exit", "#935DFE", "#1E2326");
    this->addHover("terminalView", "#935DFE", "#1E2326");
    this->addHoverFrames("TasksContainer", "#14191A;", "#14191A;");

    connect(findChild<QPushButton*>(QString::fromStdString("Exit")), &QPushButton::clicked, this, [this]() {
        QApplication::exit(0);
    });
    connect(findChild<QPushButton*>(QString::fromStdString("terminalView")), &QPushButton::clicked, this, [this]() {
        QApplication::exit(1);
    });

    connect(findChild<QPushButton*>(QString::fromStdString("ProcessorsModule")), &QPushButton::clicked, this, [this]() {
        QFrame* PROCS = this->findChild<QFrame*>(QString::fromStdString("PROCESSORS"));
        int nb = this->_cpu->getProcessors().size();
        if (!PROCS->isVisible()) {
            PROCS->setVisible(true);
            ui->ProcessorsModule->setStyleSheet("color:white;background-color: #FAA069;");
            for (int i = 0; i < nb; i++) {
                std::string name = "bar" + std::to_string(i + 1);
                QFrame* bar = this->findChild<QFrame*>(QString::fromStdString(name));
                bar->setVisible(true);
            }
        } else {
            PROCS->setVisible(false);
            for (int i = 0; i < nb; i++) {
                std::string name = "bar" + std::to_string(i + 1);
                QFrame* bar = this->findChild<QFrame*>(QString::fromStdString(name));
                bar->setVisible(false);
            }
            ui->ProcessorsModule->setStyleSheet("color:white;background-color: #1E2326;");
        }
    });

    connect(findChild<QPushButton*>(QString::fromStdString("KernelModule")), &QPushButton::clicked, this, [this]() {
        QFrame* PROCS = this->findChild<QFrame*>(QString::fromStdString("KERNEL"));
        if (!PROCS->isVisible()) {
            PROCS->setVisible(true);
            ui->KernelModule->setStyleSheet("color:white;background-color: #FAA069;");
        } else {
            PROCS->setVisible(false);
            ui->KernelModule->setStyleSheet("color:white;background-color: #1E2326;");
        }
    });

    connect(findChild<QPushButton*>(QString::fromStdString("UserModule")), &QPushButton::clicked, this, [this]() {
        QFrame* PROCS = this->findChild<QFrame*>(QString::fromStdString("UserData"));
        if (!PROCS->isVisible()) {
            PROCS->setVisible(true);
            ui->UserModule->setStyleSheet("color:white;background-color: #FAA069;");
        } else {
            PROCS->setVisible(false);
            ui->UserModule->setStyleSheet("color:white;background-color: #1E2326;");
        }
    });

    connect(findChild<QPushButton*>(QString::fromStdString("CPUModule")), &QPushButton::clicked, this, [this]() {
        QFrame* PROCS = this->findChild<QFrame*>(QString::fromStdString("frame_4"));
        QFrame* PROCS1 = this->findChild<QFrame*>(QString::fromStdString("label_8"));
        QFrame* PROCS2 = this->findChild<QFrame*>(QString::fromStdString("CPU_PERCENT"));
        if (!PROCS->isVisible()) {
            PROCS->setVisible(true);
            PROCS1->setVisible(true);
            PROCS2->setVisible(true);
            ui->CPUModule->setStyleSheet("color:white;background-color: #FAA069;");
        } else {
            PROCS->setVisible(false);
            PROCS1->setVisible(false);
            PROCS2->setVisible(false);
            ui->CPUModule->setStyleSheet("color:white;background-color: #1E2326;");
        }
    });

    connect(findChild<QPushButton*>(QString::fromStdString("TasksManagerModule")), &QPushButton::clicked, this, [this]() {
        QFrame* PROCS = this->findChild<QFrame*>(QString::fromStdString("TasksContainer"));
        if (!PROCS->isVisible()) {
            PROCS->setVisible(true);
            ui->TasksManagerModule->setStyleSheet("color:white;background-color: #FAA069;");
        } else {
            PROCS->setVisible(false);
            ui->TasksManagerModule->setStyleSheet("color:white;background-color: #1E2326;");
        }
    });

    connect(findChild<QPushButton*>(QString::fromStdString("RAMModule")), &QPushButton::clicked, this, [this]() {
        QFrame* PROCS = this->findChild<QFrame*>(QString::fromStdString("RAM_PERCENT"));
        QFrame* PROCS1 = this->findChild<QFrame*>(QString::fromStdString("label_9"));
        QFrame* PROCS2 = this->findChild<QFrame*>(QString::fromStdString("frame_5"));
        QFrame* PROCS3 = this->findChild<QFrame*>(QString::fromStdString("frame_9"));
        if (!PROCS->isVisible()) {
            PROCS->setVisible(true);
            PROCS1->setVisible(true);
            PROCS2->setVisible(true);
            PROCS3->setVisible(true);
            ui->RAMModule->setStyleSheet("color:white;background-color: #FAA069;");
        } else {
            PROCS->setVisible(false);
            PROCS1->setVisible(false);
            PROCS2->setVisible(false);
            PROCS3->setVisible(false);
            ui->RAMModule->setStyleSheet("color:white;background-color: #1E2326;");
        }
    });


    QApplication::exit(34);
    for (int i = 1; i <= 15; i++) {
        std::string task = "task" + std::to_string(i);
        this->addHoverFrames(task, "#935DFE", "#252C2F");
    }

    this->startTimer(1);
}

void MainWindow::createBar(std::string name, int x, int y, std::string color)
{
    QFrame* ProcessBar = new QFrame(this);
    ProcessBar->setGeometry(QRect(x, y, 230, 41));
    ProcessBar->setStyleSheet("background-color:#1E2326; border-radius:5px; opacity:0.4;");
    ProcessBar->setFrameShape(QFrame::StyledPanel);
    ProcessBar->setFrameShadow(QFrame::Raised);
    ProcessBar->setObjectName(QString::fromStdString(name));

    QFrame* frame_18 = new QFrame(ProcessBar);
    frame_18->setGeometry(QRect(0, 0, 101, 41));
    std::string str1 = "background-color:";
    std::string str2 = str1 + color;
    frame_18->setStyleSheet(QString::fromStdString(str2));
    frame_18->setFrameShape(QFrame::StyledPanel);
    frame_18->setFrameShadow(QFrame::Raised);

    QLabel* percentLabel = new QLabel(frame_18);
    percentLabel->setFixedSize(230, 41);
    percentLabel->setAlignment(Qt::AlignCenter);
    percentLabel->setStyleSheet("color:white; font-size:15px;");
    percentLabel->setText("0%");

}

void MainWindow::updateBar(std::string name, int value)
{
    QFrame* ProcessBar = findChild<QFrame*>(QString::fromStdString(name));
    QFrame* frame_18 = ProcessBar->findChild<QFrame*>();
    frame_18->setGeometry(QRect(0, 0, (value*230)/100, 41));

    QLabel* percentLabel = frame_18->findChild<QLabel*>();
    percentLabel->setText(QString::number(value) + "%");
    percentLabel->setFixedSize((value*230)/100, 41);
    percentLabel->setAlignment(Qt::AlignCenter);
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    (void)event;
    static int time = 0;

    if (time < 500) {
        if (this->tasks.empty()) {
            this->_tasksMonitor->updateTasks();
            this->tasks = this->_tasksMonitor->getTasks();
        }
        this->displayTask();
        time++;
        return;
    }
    time = 0;
    this->_cpu->updateCpu();
    this->_ram->updateRam();
    this->_tasksMonitor->updateTasks();
    this->_network->updateNetwork();


    std::vector<components::Object *> processors = this->_cpu->getProcessors();
    for (unsigned int i = 0; i < processors.size(); i++) {
        std::string name = "bar" + std::to_string(i + 1);
        double value = this->_cpu->getProcessorPercent(processors[i]);
        this->updateBar(name, value);
    }

    ui->date->setText(QString::fromStdString(this->_dataTimes->getDate()));
    ui->time->setText(QString::fromStdString(this->_dataTimes->getLocaltime()));

    double cpuUsage = this->_cpu->getCpuPercent();
    ui->CPU_USAGE->setFixedSize((cpuUsage*631)/100, 121);

    double ramUsed = std::stod(this->_ram->getUsedRam()->getData()) / 1000;
    double ramTotal = std::round((std::stod(this->_ram->getTotalRam()->getData()) / 1000000) * 100.0) / 100.0;
    double freeRam = std::stod(this->_ram->getFreeRam()->getData()) / 1000000;
    double ramUsage = (ramUsed/ramTotal)*100;
    ui->RAM_USAGE->setFixedSize((ramUsage*631)/100, 121);

    ui->CPU_PERCENT->setText(QString::number(std::round(cpuUsage)) + "%");
    ui->RAM_PERCENT->setText(QString::number(std::round(ramUsage)) + "%");

    ui->total_ram_bar->setFixedSize(251, 121);
    ui->total_ram_go->setText(QString::number(ramTotal) + " Go");
    double usedPercent = (ramUsed/ramTotal)*100;
    ui->used_ram_bar->setFixedSize((usedPercent*251)/100, 121);
    ui->used_ram_go->setText(QString::number(std::round(ramUsed * 100.0) / 100.0) + " / " + QString::number(ramTotal) + " Go");
    double freePercent = (freeRam/ramTotal)*100;
    ui->free_ram_bar->setFixedSize((freePercent*251)/100, 121);
    ui->free_ram->setText(QString::number(std::round(freeRam * 100.0) / 100.0) + " / " + QString::number(ramTotal) + " Go");

    double sharedRam = std::stod(this->_ram->getSharedRam()->getData()) / 1000000;
    double bufferRam = std::stod(this->_ram->getBufferRam()->getData()) / 1000000;
    double cachedRam = ramTotal - (ramUsed + sharedRam + bufferRam + freeRam);
    double sharedPercent = (sharedRam/ramTotal)*100;
    ui->shared_ram_bar->setFixedSize((sharedPercent*251)/100, 121);
    ui->shared_ram_go->setText(QString::number(std::round(sharedRam * 100.0) / 100.0) + " / " + QString::number(ramTotal) + " Go");
    double bufferPercent = (bufferRam/ramTotal)*100;
    ui->buffer_ram_bar->setFixedSize((bufferPercent*251)/100, 121);
    ui->buffer_ram_go->setText(QString::number(std::round(bufferRam * 100.0) / 100.0) + " / " + QString::number(ramTotal) + " Go");
    double ramPercent = (cachedRam/ramTotal)*100;
    ui->cached_ram_bar->setFixedSize((ramPercent*251)/100, 121);
    ui->cached_ram_go->setText(QString::number(std::round(cachedRam * 100.0) / 100.0) + " / " + QString::number(ramTotal) + " Go");

    double swapTotal = std::stod(this->_ram->getSwapTotal()->getData()) / 1000000;
    double swapFree = std::stod(this->_ram->getSwapFree()->getData()) / 1000000;
    double swapUsed = std::stod(this->_ram->getSwapUsed()->getData()) / 1000000;
    double swapTotalPercent = (swapTotal/ramTotal)*100;
    double swapFreePercent = (swapFree/ramTotal)*100;
    double swapUsedPercent = (swapUsed/ramTotal)*100;
    ui->swap_total_ram_bar->setFixedSize((swapTotalPercent*251)/100, 121);
    ui->swap_total_ram_go->setText(QString::number(std::round(swapTotal * 100.0) / 100.0) + " / " + QString::number(ramTotal) + " Go");
    ui->swap_free_ram_bar->setFixedSize((swapFreePercent*251)/100, 121);
    ui->swap_free_ram_go->setText(QString::number(std::round(swapFree * 100.0) / 100.0) + " / " + QString::number(ramTotal) + " Go");
    ui->swap_user_ram_bar->setFixedSize((swapUsedPercent*251)/100, 121);
    ui->swap_user_ram_go->setText(QString::number(std::round(swapUsed * 100.0) / 100.0) + " / " + QString::number(ramTotal) + " Go");

    this->tasks.clear();
    this->tasks = this->_tasksMonitor->getTasks();
    int tasks = this->tasks.size();
    int running = this->_tasksMonitor->getOnly("R").size();
    int idle = this->_tasksMonitor->getOnly("I").size();
    int sleeping = this->_tasksMonitor->getOnly("S").size();
    ui->tasks->setText("Tasks : " + QString::number(tasks));
    ui->running->setText("Running : " + QString::number(running));
    ui->idle->setText("Idle : " + QString::number(idle));
    ui->sleeping->setText("Sleeping : " + QString::number(sleeping));

}

void MainWindow::displayTask()
{
    int e = 1;
    for (int i = this->getIndexMin(); i <= this->getIndexMax(); i++,e++) {
        std::string task = "task" + std::to_string(e);
        std::string PID = e == 1 ? "pid" : "pid_" + std::to_string(e);
        std::string Name = e == 1 ? "name" : "name_" + std::to_string(e);
        std::string Usage = e == 1 ? "usage" : "usage_" + std::to_string(e);
        std::string Cmd = e == 1 ? "cmd" : "cmd_" + std::to_string(e);
        std::string State = e == 1 ? "state" : "state_" + std::to_string(e);
        QLabel *label = findChild<QLabel*>(QString::fromStdString(PID));
        QLabel *name = findChild<QLabel*>(QString::fromStdString(Name));
        QLabel *usage = findChild<QLabel*>(QString::fromStdString(Usage));
        QLabel *cmd = findChild<QLabel*>(QString::fromStdString(Cmd));
        QLabel *state = findChild<QLabel*>(QString::fromStdString(State));
        label->setText(QString::number(this->tasks[i]->getPid()));
        name->setText(QString::fromStdString(this->tasks[i]->getFile("status")->getItem("Name")->getData().replace(0, 1, "")));
        usage->setText(QString::fromStdString(this->tasks[i]->getFile("status")->getItem("Cpu Usage")->getData().replace(0, 1, "")));
        cmd->setText(QString::fromStdString(this->tasks[i]->getFile("cmdline")->getItem("cmdline")->getData()));
        state->setText(QString::fromStdString(this->tasks[i]->getFile("status")->getItem("State")->getData()));
    }
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event) {

    for (unsigned int i = 0; i < this->_buttons.size(); i++) {
        if (obj == this->_buttons[i]->button) {
            if (event->type() == QEvent::Enter) {
                frameEntered(this->_buttons[i]);
            } else if (event->type() == QEvent::Leave) {
                frameLeft(this->_buttons[i]);
            }
        }
    }
    for (unsigned int i = 0; i < this->_frames.size(); i++) {
        if (obj == this->_frames[i]->frame) {
            if (event->type() == QEvent::Enter) {
                frameEntered(this->_frames[i]);
            } else if (event->type() == QEvent::Leave) {
                frameLeft(this->_frames[i]);
            }
        }
    }
    return QMainWindow::eventFilter(obj, event);
}

void MainWindow::frameEntered(Element* elem) {
    if (!elem->isFrame)
        elem->button->setStyleSheet("border-radius:10px;color:white; background-color: " + QString::fromStdString(elem->_color1) + "");
    else {
        if (elem->frame->objectName().toStdString() == "TasksContainer")
            this->setCanScroll(true);
        elem->frame->setStyleSheet("border-radius:10px;color:white; background-color: " + QString::fromStdString(elem->_color1) + "");
    }
}

void MainWindow::frameLeft(Element* elem) {
    if (!elem->isFrame)
        elem->button->setStyleSheet("border-radius:10px;color:white; background-color: " + QString::fromStdString(elem->_color2) + "");
    else {
        if (elem->frame->objectName().toStdString() == "TasksContainer")
            this->setCanScroll(false);
        elem->frame->setStyleSheet("border-radius:10px;color:white; background-color: " + QString::fromStdString(elem->_color2) + "");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

