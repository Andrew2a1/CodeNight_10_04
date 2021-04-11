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

    connect(ui->habits, &HabitWidgetContainer::requestRemove,
            this, &MainAppWidget::removeHabit);

    connect(ui->optionsBtn, &QPushButton::clicked,
            this, &MainAppWidget::optionsPressed);

    timer->start();
}

MainAppWidget::~MainAppWidget()
{
    delete ui;
}

void MainAppWidget::setUser(User *user)
{
    this->user = user;

    if(user)
        ui->usernameLabel->setText("Welcome " + user->getName());
}

User *MainAppWidget::getUser() const
{
    return user;
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
    if(habit->getRepeatPeriod() == RepeatPeriod::None){
        removeHabit(habit);
        addPowerPoints(habit->getValue());
    }
    else if(habit->getRepeatPeriod() == RepeatPeriod::Everyday){
        if(QDateTime::currentDateTime().daysTo(habit->getDeadline())<=1){
            habit->setDeadline(habit->getDeadline().addDays(1));
            addPowerPoints(habit->getValue());
        }
        else
            QMessageBox::information(this, "Come back tomorrow","You have done this task today");
    }
    else if(habit->getRepeatPeriod() == RepeatPeriod::Everyweek){

        if(QDateTime::currentDateTime().daysTo(habit->getDeadline())<=7){
            habit->setDeadline(habit->getDeadline().addDays(7));
            addPowerPoints(habit->getValue());
        }
        else
            QMessageBox::information(this, "Come back next week","You have done this task this week");
    }


    updateHabits();
}

void MainAppWidget::addPowerPoints(int points)
{
    Unicorn *unicorn = user->getUnicorn();
    unicorn->addPower(points);

    ui->powerProgress->setValue(unicorn->getPower());
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
                                     "You have not "
                                     "finished your "
                                     "task on time: " + habit->getName());

            if(habit->getRepeatPeriod() == RepeatPeriod::None)
                removeHabit(habit);
            else if(habit->getRepeatPeriod() == RepeatPeriod::Everyday)
                habit->setDeadline(habit->getDeadline().addDays(1));
            else if(habit->getRepeatPeriod() == RepeatPeriod::Everyweek)
                habit->setDeadline(habit->getDeadline().addDays(7));

            updateHabits();
            addPowerPoints(-habit->getValue());
        }
    }
}

void MainAppWidget::on_addHabitBtn_clicked()
{
    emit btnAddHabitPressed();
}
