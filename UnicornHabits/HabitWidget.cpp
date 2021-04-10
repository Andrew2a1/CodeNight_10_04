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

    ui->nameLabel->setText(QString::fromStdString(habit->getName()));
    ui->descLabel->setText(QString::fromStdString(habit->getDescription()));
}

HabitWidget::~HabitWidget()
{
    delete ui;
}

void HabitWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->type() == QEvent::MouseButtonPress)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Question", "Finished?",
                                      QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            emit habitDone(habit->getValue());
        }
    }

    QWidget::mousePressEvent(event);
}
