#include "MainAppWidget.h"
#include "ui_MainAppWidget.h"

#include "AddHabitWidget.h"
#include "mainwindow.h"

#include <QLabel>
#include <QVBoxLayout>

MainAppWidget::MainAppWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainAppWidget)
{
    ui->setupUi(this);

    connect(ui->habits, &HabitWidgetContainer::powerPointsAdded,
            this, &MainAppWidget::addPowerPoints);
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

void MainAppWidget::updateHabits()
{
    ui->habits->clear();

    for(const auto& habit: user->getHabits())
        ui->habits->addHabit(habit);
}

void MainAppWidget::addPowerPoints(int points)
{
    ui->powerProgress->setValue(ui->powerProgress->value() + points);
}

void MainAppWidget::on_addHabitBtn_clicked()
{
    emit btnAddHabitPressed();
}
