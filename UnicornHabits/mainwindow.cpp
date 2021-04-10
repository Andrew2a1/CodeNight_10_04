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

    ui->stackedWidget->addWidget(loginWidget);
    ui->stackedWidget->addWidget(mainWidget);

    ui->stackedWidget->setCurrentWidget(loginWidget);

    connect(loginWidget, &LoginWidget::loginPressed,
            this, &MainWindow::login);

    connect(mainWidget, &MainAppWidget::btnAddHabitPressed,
            this, &MainWindow::createHabitWidget);
}

MainWindow::~MainWindow()
{
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
    mainWidget->setUser(new User(username));
    ui->stackedWidget->setCurrentWidget(mainWidget);
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
