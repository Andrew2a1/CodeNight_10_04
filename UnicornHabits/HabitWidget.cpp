#include "HabitWidget.h"
#include "ui_HabitWidget.h"

#include <QMouseEvent>
#include <QMessageBox>

HabitWidget::HabitWidget(std::shared_ptr<Habit> habit,
                         QWidget *parent) :
    QWidget(parent),
    habit(habit),
    ui(new Ui::HabitWidget)
{
    ui->setupUi(this);

    ui->nameLabel->setText(QString::fromStdString(habit->getDetails()));
    ui->repeatLabel->setText(QString::fromStdString(habit->getRepeatPeriod()));
}

HabitWidget::~HabitWidget()
{
    delete ui;
}

std::shared_ptr<Habit> HabitWidget::getHabit() const
{
    return habit;
}

void HabitWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->type() == QEvent::MouseButtonPress &&
            event->button() == Qt::LeftButton)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Question", "Finished?",
                                      QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            emit habitDone(habit);
        }
    }

    QWidget::mousePressEvent(event);
}
