#include "QT/QT5/mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include "../include/ncurses/ncursesApplications.hpp"

int initQT(int ac, char **av)
{
    QApplication a(ac, av);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "QT5_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    MainWindow w;
    w.show();
    return a.exec();
}

int main(int ac, char *av[])
{
    ncursesApplications *ncurses = new ncursesApplications();

    int fd = initQT(ac, av);
    if (fd) {
        ncurses->init();
        while (ncurses->isRunning()) {
            ncurses->update();
            ncurses->display();
            usleep(50000);
        }
        if (ncurses->_switch == true)
            main(ac, av);
        ncurses->destroy(true);
    }
    return 0;
}
