#include "HabitWidget.h"
#include "ui_HabitWidget.h"

#include <QMouseEvent>
#include <QMessageBox>
#include <QInputDialog>

QString fromRepeatPeriod(RepeatPeriod period)
{
    switch (period)
    {
    case RepeatPeriod::Everyday:
        return "Everyday";
    case RepeatPeriod::Everyweek:
        return "Everyweek";
    default:
        return "";
    }
}

HabitWidget::HabitWidget(std::shared_ptr<Habit> habit,
                         QWidget *parent) :
    QWidget(parent),
    habit(habit),
    ui(new Ui::HabitWidget)
{
    ui->setupUi(this);
    refresh();
}

HabitWidget::~HabitWidget()
{
    delete ui;
}

std::shared_ptr<Habit> HabitWidget::getHabit() const
{
    return habit;
}

void HabitWidget::refresh()
{
    ui->nameLabel->setText(habit->getName());
    ui->deadlineLabel->setText(habit->getDeadline().toString());
    ui->repeatLabel->setText(fromRepeatPeriod(habit->getRepeatPeriod()));

    if(habit->getAmountUnit() != AmountUnit::None)
        ui->amountLabel->setText("Amount: " + QString::number(habit->getAmount()));
    else
        ui->amountLabel->setText("");
}

void HabitWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->type() == QEvent::MouseButtonPress &&
            event->button() == Qt::LeftButton)
    {
        if(habit->getAmountUnit() != AmountUnit::None)
        {
            double value = QInputDialog::getDouble(this, "Question",
                                                   "How much have you done?");
            if(value > 0)
                habit->setAmount(std::max(0.0, habit->getAmount() - value));

            if(habit->getAmount() < 0.001)
            {
                if(habit->getRepeatPeriod() != RepeatPeriod::None)
                    habit->resetAmount();
                emit habitDone(habit);
            }

        }
        else
        {
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(this, "Question", "Finished?",
                                          QMessageBox::Yes | QMessageBox::No);

            if (reply == QMessageBox::Yes) {
                emit habitDone(habit);
            }
        }

        refresh();
    }

    QWidget::mousePressEvent(event);
}
