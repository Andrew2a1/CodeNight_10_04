#include "AddHabitWidget.h"
#include "ui_AddHabitWidget.h"

#include "mainwindow.h"
#include "todohabit.h"
#include "amounthabit.h"

#include <memory>

HabitType fromString(const QString &habitStr)
{
    if(habitStr == "Time")
        return HabitType::Time;

    else if(habitStr == "Calories")
        return HabitType::Calories;

    return HabitType::Volume;
}

AddHabitWidget::AddHabitWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddHabitWidget)
{
    ui->setupUi(this);
    on_habitType_currentTextChanged("Todo");
    on_shouldRepeat_toggled(false);
}

AddHabitWidget::~AddHabitWidget()
{
    delete ui;
}

void AddHabitWidget::on_okBtn_clicked()
{
    Habit *habit;

    std::string habitName = ui->habitName->text().toStdString();
    std::string habitDesc = ui->habitDescription->text().toStdString();
    std::string period = ui->repeatPeriod->text().toStdString();

    if(ui->habitType->currentText() == "Todo")
    {
        habit = new TodoHabit(habitDesc, habitName,
                              period, ui->deadline->dateTime());
    }
    else
    {
        habit = new AmountHabit(habitDesc, habitName,
                                period, ui->amount->value(),
                                fromString(ui->units->currentText()));
    }

    emit habitCreated(habit);
}

void AddHabitWidget::on_cancelBtn_clicked()
{
    emit habitCreated(nullptr);
}

void AddHabitWidget::on_habitType_currentTextChanged(const QString &arg1)
{
    if(arg1 == "Todo")
    {
        ui->unitsLabel->hide();
        ui->units->hide();

        ui->amountLabel->hide();
        ui->amount->hide();

        ui->deadlineLabel->show();
        ui->deadline->show();
    }
    else
    {
        ui->unitsLabel->show();
        ui->units->show();

        ui->amountLabel->show();
        ui->amount->show();

        ui->deadlineLabel->hide();
        ui->deadline->hide();
    }
}

void AddHabitWidget::on_shouldRepeat_toggled(bool checked)
{
    ui->repeatPeriod->setEnabled(checked);
}
