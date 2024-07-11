QT       += core gui
QT += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    battleshipgame.cpp \
    blast.cpp \
    boardsquare.cpp \
    cpu.cpp \
    cpuships.cpp \
    dialog.cpp \
    displayships.cpp \
    gameships.cpp \
    human.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    player.cpp \
    selectship.cpp \
    signup.cpp

HEADERS += \
    battleshipgame.h \
    blast.h \
    boardsquare.h \
    cpu.h \
    cpuships.h \
    dialog.h \
    displayships.h \
    gameships.h \
    human.h \
    login.h \
    mainwindow.h \
    player.h \
    selectship.h \
    signup.h \
    vars.h

FORMS += \
    dialog.ui \
    login.ui \
    mainwindow.ui \
    signup.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
