#include "MainAppWidget.h"
#include "ui_MainAppWidget.h"

#include "AddHabitWidget.h"
#include "mainwindow.h"

#include <QMessageBox>
#include <QLabel>
#include <QVBoxLayout>

MainAppWidget::MainAppWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainAppWidget)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    timer->setInterval(1000);
    timer->setSingleShot(false);

    connect(timer, &QTimer::timeout,
            this, &MainAppWidget::checkIfExpired);

    connect(ui->habits, &HabitWidgetContainer::habitFinished,
            this, &MainAppWidget::acceptHabit);

    timer->start();
}

MainAppWidget::~MainAppWidget()
{
    delete ui;
}

void MainAppWidget::setUser(User *user)
{
    this->user = user;
}

void MainAppWidget::addHabit(std::shared_ptr<Habit> habit)
{
    user->addHabit(habit);
}

void MainAppWidget::removeHabit(std::shared_ptr<Habit> habit)
{
    user->removeHabit(habit);
    updateHabits();
}

void MainAppWidget::updateHabits()
{
    ui->habits->clear();

    for(const auto& habit: user->getHabits())
        ui->habits->addHabit(habit);
}

void MainAppWidget::acceptHabit(std::shared_ptr<Habit> habit)
{
    addPowerPoints(habit->getValue());

    if(habit->getRepeatPeriod().empty())
        removeHabit(habit);
}

void MainAppWidget::addPowerPoints(int points)
{
    ui->powerProgress->setValue(ui->powerProgress->value() + points);
}

void MainAppWidget::checkIfExpired()
{
    if(!user)
        return;

    for(const auto &habit : user->getHabits())
    {
        if(habit->hasExpired())
        {
            QMessageBox::information(this, "Task expired",
                                     QString::fromStdString("You have not "
                                                            "finished your "
                                                            "task on time: " + habit->getName()));
            removeHabit(habit);
            addPowerPoints(-habit->getValue());
        }
    }
}

void MainAppWidget::on_addHabitBtn_clicked()
{
    emit btnAddHabitPressed();
}
