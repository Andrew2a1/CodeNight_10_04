#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "AddHabitWidget.h"


#include <QtDebug>
#include <memory>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    loginWidget = new LoginWidget(this);
    mainWidget = new MainAppWidget(this);
    logoutWidget = new LogoutWidget(this);

    ui->stackedWidget->addWidget(loginWidget);
    ui->stackedWidget->addWidget(mainWidget);
    ui->stackedWidget->addWidget(logoutWidget);

    ui->stackedWidget->setCurrentWidget(loginWidget);

    connect(loginWidget, &LoginWidget::loginPressed,
            this, &MainWindow::login);

    connect(mainWidget, &MainAppWidget::btnAddHabitPressed,
            this, &MainWindow::createHabitWidget);

    connect(mainWidget, &MainAppWidget::optionsPressed,
            this, [=](){ui->stackedWidget->setCurrentWidget(logoutWidget);});

    connect(logoutWidget, &LogoutWidget::backPressed,
            this, [=](){ui->stackedWidget->setCurrentWidget(mainWidget);});

    connect(logoutWidget, &LogoutWidget::logoutPressed,
            this, &MainWindow::logout);
}

MainWindow::~MainWindow()
{
    logout();
    delete ui;
}

void MainWindow::addHabit(Habit *habit)
{
    if(habit == nullptr)
        return;

    std::shared_ptr<Habit> habitPtr(habit);
    mainWidget->addHabit(habitPtr);
    mainWidget->updateHabits();
}

void MainWindow::login(const QString &username)
{
    User* user = new User(username);
    user->deserialize();

    mainWidget->setUser(user);
    mainWidget->updateHabits();

    ui->stackedWidget->setCurrentWidget(mainWidget);
}

void MainWindow::logout()
{
    User *user = mainWidget->getUser();
    if(user)
        user->serialize();

    mainWidget->setUser(nullptr);
    ui->stackedWidget->setCurrentWidget(loginWidget);

    delete user;
}

void MainWindow::createHabitWidget()
{
    AddHabitWidget* addHabitWidget = new AddHabitWidget(this);
    ui->stackedWidget->addWidget(addHabitWidget);
    ui->stackedWidget->setCurrentWidget(addHabitWidget);

    connect(addHabitWidget, &AddHabitWidget::habitCreated,
            this, &MainWindow::addHabit);

    connect(addHabitWidget, &AddHabitWidget::habitCreated,
            this,
            [=](){
        ui->stackedWidget->setCurrentWidget(mainWidget);
    });
}
