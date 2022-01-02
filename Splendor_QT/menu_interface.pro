QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    end.cpp \
    game_interface.cpp \
    game_setting.cpp \
    main.cpp \
    mainwindow.cpp \
    materiel.cpp \
    ostream.cpp \
    splendor.cpp \
    vuecarte.cpp

HEADERS += \
    end.h \
    game_interface.h \
    game_setting.h \
    mainwindow.h \
    splendor.h \
    materiel.h \
    json.hpp \
    vuecarte.h

FORMS += \
    end.ui \
    game_interface.ui \
    game_setting.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
