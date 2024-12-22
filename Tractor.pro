QT       += core gui
QT += serialport
QT += gamepad

#INCLUDEPATH +=  C:/QT/Qt5.14.2/5.14.2/mingw73_64/bin
LIBS += -LSDL2.dll

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11


DEFINES += QT_DEPRECATED_WARNINGS


SOURCES += \
    main.cpp \
    mainwindow.cpp \
    servosetting.cpp

HEADERS += \
    mainwindow.h \
    servosetting.h

FORMS += \
    mainwindow.ui \
    servosetting.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


