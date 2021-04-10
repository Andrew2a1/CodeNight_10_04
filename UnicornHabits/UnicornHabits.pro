QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AddHabitWidget.cpp \
    LoginWidget.cpp \
    MainAppWidget.cpp \
    Unicorn.cpp \
    User.cpp \
    amounthabit.cpp \
    habit.cpp \
    main.cpp \
    mainwindow.cpp \
    todohabit.cpp

HEADERS += \
    AddHabitWidget.h \
    LoginWidget.h \
    MainAppWidget.h \
    Unicorn.h \
    User.h \
    mainwindow.h \
    amounthabit.h \
    habit.h \
    mainwindow.h \
    todohabit.h

FORMS += \
    AddHabitWidget.ui \
    LoginWidget.ui \
    MainAppWidget.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
