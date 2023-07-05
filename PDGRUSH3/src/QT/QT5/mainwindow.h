#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFrame>
#include <QPushButton>
#include <vector>
#include <QWheelEvent>
#include "../../../include/core/core.hpp"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Element {
    public:
        Element(QPushButton* button, std::string _color1, std::string _color2)
        {
            this->button = button;
            this->_color1 = _color1;
            this->_color2 = _color2;
        };
        Element(QFrame* frame, std::string _color1, std::string _color2)
        {
            this->frame = frame;
            this->_color1 = _color1;
            this->_color2 = _color2;
            this->isFrame = true;
        };
        ~Element() {};
        QPushButton* button;
        QFrame* frame;
        std::string _color1;
        std::string _color2;
        bool isFrame = false;
};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void update();
    void displayTask();
    void timerEvent(QTimerEvent *event);
    void addHover(const std::string name, std::string color1, std::string color2)
    {
        QPushButton *button = findChild<QPushButton*>(QString::fromStdString(name));
        if (!button) return;
        Element *element = new Element(button, color1, color2);
        this->_buttons.push_back(element);
        element->button->installEventFilter(this);
    }
    void addHoverFrames(const std::string name, std::string color1, std::string color2)
    {
        QFrame *frame = findChild<QFrame*>(QString::fromStdString(name));
        if (!frame) return;
        Element *element = new Element(frame, color1, color2);
        this->_frames.push_back(element);
        element->frame->installEventFilter(this);
    }

    IMonitorModule::Kernel *_kernel;
    IMonitorModule::DataTimes *_dataTimes;
    IMonitorModule::User *_user;
    IMonitorModule::Cpu *_cpu;
    IMonitorModule::Tasks::TasksMonitor *_tasksMonitor;
    IMonitorModule::Ram *_ram;
    IMonitorModule::Network *_network;

    void createBar(std::string name, int x, int y, std::string color);
    void updateBar(std::string name, int value);
    int getIndexMin() const { return this->indexMin; };
    int getIndexMax() const { return this->indexMax; };
    void setIndexMin(int index) { indexMin = index; };
    void setIndexMax(int index) { indexMax = index; };
    void setCanScroll(bool can) { canScroll = can; };
    bool getCanScroll() const { return canScroll; };
    void on_Exit_clicked();

    private:
        Ui::MainWindow *ui;
        void frameEntered(Element*);
        void frameLeft(Element*);
        std::vector<Element*> _buttons;
        std::vector<Element*> _frames;
        int indexMin = 0;
        int indexMax = 14;
        bool canScroll = false;
        std::vector<IMonitorModule::Tasks::TaskItem *> tasks;
    protected:
        bool eventFilter(QObject *obj, QEvent *event) override;
        void wheelEvent(QWheelEvent *event)
        {
            if (this->getCanScroll()) {
                if (event->delta() > 0) {
                    if (this->getIndexMin() > 0) {
                        this->setIndexMin(this->getIndexMin() - 1);
                        this->setIndexMax(this->getIndexMax() - 1);
                    }
                } else if (this->getIndexMax() + 1 < (int)this->tasks.size() - 1) {
                    this->setIndexMin(this->getIndexMin() + 1);
                    this->setIndexMax(this->getIndexMax() + 1);
                }
            }
        }

};

#endif // MAINWINDOW_H
