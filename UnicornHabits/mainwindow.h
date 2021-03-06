#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "User.h"
#include "habit.h"

#include "LoginWidget.h"
#include "MainAppWidget.h"
#include "LogoutWidget.h"
#include "StudyModeWidget.h"
#include "RewardWidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    LoginWidget *loginWidget;
    MainAppWidget *mainWidget;
    LogoutWidget *logoutWidget;
    StudyModeWidget *studyMode;
    RewardWidget *rewardWidget;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void addHabit(Habit *habit);

private slots:
    void login(const QString &username);
    void logout();

    void createHabitWidget();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
