QT       += core gui svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AddHabitWidget.cpp \
    HabitAmountDialog.cpp \
    HabitDescription.cpp \
    HabitFinishedDialog.cpp \
    HabitWidget.cpp \
    HabitWidgetContainer.cpp \
    LoginWidget.cpp \
    LogoutWidget.cpp \
    MainAppWidget.cpp \
    PowerBar.cpp \
    RewardWidget.cpp \
    StudyModeWidget.cpp \
    SvgWidget.cpp \
    mainwindow.cpp \
    Unicorn.cpp \
    User.cpp \
    habit.cpp \
    main.cpp

HEADERS += \
    AddHabitWidget.h \
    HabitAmountDialog.h \
    HabitDescription.h \
    HabitFinishedDialog.h \
    HabitWidget.h \
    HabitWidgetContainer.h \
    LoginWidget.h \
    LogoutWidget.h \
    MainAppWidget.h \
    PowerBar.h \
    RewardWidget.h \
    StudyModeWidget.h \
    SvgWidget.h \
    Unicorn.h \
    User.h \
    mainwindow.h \
    habit.h

FORMS += \
    AddHabitWidget.ui \
    HabitAmountDialog.ui \
    HabitDescription.ui \
    HabitFinishedDialog.ui \
    HabitWidget.ui \
    HabitWidgetContainer.ui \
    LoginWidget.ui \
    LogoutWidget.ui \
    MainAppWidget.ui \
    RewardWidget.ui \
    StudyModeWidget.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources/res.qrc
