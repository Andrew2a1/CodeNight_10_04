#include "HabitWidget.h"
#include "ui_HabitWidget.h"

#include <QMouseEvent>
#include <QMessageBox>
#include <QInputDialog>

#include <QPainter>
#include <QPaintEvent>
#include <QPainterPath>

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

QString fromAmountUnits(AmountUnit units)
{
    switch (units)
    {
    case AmountUnit::Hours:
        return "Hours";
    case AmountUnit::Kcals:
        return "Kcals";
    case AmountUnit::Liters:
        return "Liters";
    case AmountUnit::Steps:
        return "Steps";
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
    //ui->nameLabel->setText(habit->getName());
    //ui->deadlineLabel->setText(habit->getDeadline().toString(Qt::DateFormat::DefaultLocaleShortDate));
   // ui->repeatLabel->setText(fromRepeatPeriod(habit->getRepeatPeriod()));

    if(habit->getAmountUnit() != AmountUnit::None) {
       // ui->amountLabel->setText("Amount: " +
                                 //QString::number(habit->getAmount()) + " " +
                                 //fromAmountUnits(habit->getAmountUnit()));
    }
    else {
        //ui->amountLabel->setText("");
    }
    switch(habit->getAmountUnit()){
    case AmountUnit::Liters:
        ui->iconLabel->setPixmap(QPixmap(":/icons/drink2.png"));

    break;
    case AmountUnit::Hours:
        ui->iconLabel->setPixmap(QPixmap(":/icons/studymode.png"));
        break;
    case AmountUnit::Kcals:
      ui->iconLabel->setPixmap(QPixmap(":/icons/kcal.png"));
        break;
    case AmountUnit::Steps :
         ui->iconLabel->setPixmap(QPixmap(":/icons/steps.png"));
        break;
    default:
        ui->iconLabel->setPixmap(QPixmap(":/icons/todo.png"));
    }

    setMinimumWidth(sizeHint().width());
}

void HabitWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->type() == QEvent::MouseButtonPress &&
            event->button() == Qt::LeftButton)
    {
        isPressed = true;

        if(habit->getAmountUnit() != AmountUnit::None)
        {
            double value = QInputDialog::getDouble(this, "Question",
                                                   "How much have you done?",
                                                   0, 0);
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

void HabitWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
        isPressed = false;

    QWidget::mouseReleaseEvent(event);
}

void HabitWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QSize adjustedSize = this->size() - QSize(2, 2);
    QRect rect(QPoint(0,0), adjustedSize);

    if(!(QApplication::mouseButtons() & Qt::LeftButton))
        isPressed = false;

    if(isPressed)
    {
        QPainterPath path;
        path.addRect(rect);

        QPen pen(Qt::black, 1);
        painter.setPen(pen);
        painter.fillPath(path, QColor(64, 64, 64, 128));
        painter.drawPath(path);
    }

    QWidget::paintEvent(event);
}
