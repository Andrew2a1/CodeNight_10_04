QT       += core gui svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AddHabitWidget.cpp \
    HabitSerializer.cpp \
    HabitWidget.cpp \
    HabitWidgetContainer.cpp \
    LoginWidget.cpp \
    MainAppWidget.cpp \
    SvgWidget.cpp \
    mainwindow.cpp \
    Unicorn.cpp \
    User.cpp \
    amounthabit.cpp \
    habit.cpp \
    main.cpp \
    todohabit.cpp

HEADERS += \
    AddHabitWidget.h \
    HabitSerializer.h \
    HabitWidget.h \
    HabitWidgetContainer.h \
    LoginWidget.h \
    MainAppWidget.h \
    SvgWidget.h \
    Unicorn.h \
    User.h \
    mainwindow.h \
    amounthabit.h \
    habit.h \
    todohabit.h

FORMS += \
    AddHabitWidget.ui \
    HabitWidget.ui \
    HabitWidgetContainer.ui \
    LoginWidget.ui \
    MainAppWidget.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources/res.qrc
