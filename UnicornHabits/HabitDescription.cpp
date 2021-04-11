#include "HabitDescription.h"
#include "ui_HabitDescription.h"

HabitDescription::HabitDescription(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HabitDescription)
{
    ui->setupUi(this);
}

HabitDescription::~HabitDescription()
{
    delete ui;
}

void HabitDescription::setName(const QString &name)
{
    ui->nameLabel->setText(name);
}

void HabitDescription::setDeadline(const QString &deadline)
{
    ui->deadlineLabel->setText(deadline);
}

void HabitDescription::setPeriod(const QString &period)
{
    ui->repeatLabel->setText(period);
}

void HabitDescription::setAmount(const QString &amount)
{
    ui->amountLabel->setText(amount);

    if(amount.isEmpty())
        ui->amountHeader->hide();
    else
        ui->amountHeader->show();
}
