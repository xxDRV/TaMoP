QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
CONFIG += debug

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    authform.cpp \
    check_error.cpp \
    checking.cpp \
    client_hole.cpp \
    func_client.cpp \
    main.cpp \
    mainwindow.cpp \
    taskform.cpp

HEADERS += \
    authform.h \
    check_error.h \
    checking.h \
    client_hole.h \
    func_client.h \
    mainwindow.h \
    taskform.h

FORMS += \
    authform.ui \
    check_error.ui \
    checking.ui \
    mainwindow.ui \
    taskform.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
