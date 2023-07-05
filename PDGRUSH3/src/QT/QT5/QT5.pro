QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../../root.cpp \
    ../../core/cpuData.cpp \
    ../../core/dataTimes.cpp \
    ../../core/kernelInfos.cpp \
    ../../core/networkData.cpp \
    ../../core/ramInfos.cpp \
    ../../core/tasksInfos.cpp \
    ../../core/userData.cpp \
    ../../lib/object.cpp \
    ../../lib/utils.cpp \
    ../../ncurse/ncursesMagement.cpp \
    mainwindow.cpp

HEADERS += \
    ../../../include/core/core.hpp \
    ../../../include/lib/object.hpp \
    ../../../include/lib/utils.hpp \
    ../../../include/ncurses/ncursesApplications.hpp \
    mainwindow.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    QT5_fr_FR.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
