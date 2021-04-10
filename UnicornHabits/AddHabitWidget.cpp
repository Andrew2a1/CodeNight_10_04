#include "AddHabitWidget.h"
#include "ui_AddHabitWidget.h"

#include "mainwindow.h"

#include <memory>
#include <QMessageBox>

AmountUnit fromString(const QString &unitStr)
{
    if(unitStr == "Hours")
        return AmountUnit::Hours;
    else if(unitStr == "Kcals")
        return AmountUnit::Kcals;
    else if(unitStr == "Liters")
        return AmountUnit::Liters;

    return AmountUnit::None;
}

AddHabitWidget::AddHabitWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddHabitWidget)
{
    ui->setupUi(this);
    ui->deadline->setDateTime(QDateTime::currentDateTime().addDays(1));

    on_habitType_currentTextChanged("Todo");
    on_shouldRepeat_toggled(false);
}

AddHabitWidget::~AddHabitWidget()
{
    delete ui;
}

void AddHabitWidget::on_okBtn_clicked()
{
    QString habitName = ui->habitName->text();
    QString period = ui->repeatPeriod->currentText();

    if(!ui->repeatPeriod->isEnabled())
        period = "";

    QDateTime deadline = ui->deadline->dateTime();

    if(deadline < QDateTime::currentDateTime() &&
            ui->shouldRepeat->isEnabled())
    {
        QMessageBox::warning(this, "Warning",
                             "Deadline is set to date before current date");

        return;
    }

    float amount = 0.0f;

    if(ui->habitType->currentText() == "Amount")
        amount = ui->amount->value();

    Habit *habit = new Habit(habitName, deadline, amount);

    if(period == "Everyday")
        habit->setRepeatPeriod(RepeatPeriod::Everyday);
    else if(period == "Everyweek")
        habit->setRepeatPeriod(RepeatPeriod::Everyweek);

    if(ui->habitType->currentText() == "Amount")
    {
        habit->setAmount(amount);
        habit->setAmountUnit(fromString(ui->units->currentText()));
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
    }
    else
    {
        ui->unitsLabel->show();
        ui->units->show();

        ui->amountLabel->show();
        ui->amount->show();
    }
}

void AddHabitWidget::on_shouldRepeat_toggled(bool checked)
{
    ui->repeatPeriod->setEnabled(checked);
}
