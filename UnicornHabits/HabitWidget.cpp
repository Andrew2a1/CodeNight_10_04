#include "HabitWidget.h"
#include "ui_HabitWidget.h"

#include <QMouseEvent>
#include <QMessageBox>
#include <QInputDialog>

#include "amounthabit.h"

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
    ui->nameLabel->setText(QString::fromStdString(habit->getDetails()));
    ui->repeatLabel->setText(QString::fromStdString(habit->getRepeatPeriod()));
}

void HabitWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->type() == QEvent::MouseButtonPress &&
            event->button() == Qt::LeftButton)
    {
        AmountHabit *amount = dynamic_cast<AmountHabit*>(habit.get());

        if(amount)
        {
            double value = QInputDialog::getDouble(this, "Question",
                                                   "How much have you done?");
            if(value > 0)
                amount->setAmount(std::max(0.0, amount->getAmount()-value));

            if(amount->getAmount() < 0.001)
            {
                if(!amount->getRepeatPeriod().empty())
                    amount->resetToDefault();
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
