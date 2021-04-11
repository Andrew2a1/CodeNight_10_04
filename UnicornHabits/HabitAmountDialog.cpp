#include "HabitAmountDialog.h"
#include "ui_HabitAmountDialog.h"

HabitAmountDialog::HabitAmountDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HabitAmountDialog)
{
    ui->setupUi(this);
}

HabitAmountDialog::~HabitAmountDialog()
{
    delete ui;
}

float HabitAmountDialog::getAmountDone()
{
    return ui->amountDone->value();
}

void HabitAmountDialog::setName(const QString &name)
{
    ui->habitDesc->setName(name);
}

void HabitAmountDialog::setDeadline(const QString &deadline)
{
    ui->habitDesc->setDeadline(deadline);
}

void HabitAmountDialog::setPeriod(const QString &period)
{
    ui->habitDesc->setPeriod(period);
}

void HabitAmountDialog::setAmount(const QString &amount)
{
    ui->habitDesc->setAmount(amount);
}
