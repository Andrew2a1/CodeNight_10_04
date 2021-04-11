#include "HabitFinishedDialog.h"
#include "ui_HabitFinishedDialog.h"

#include "HabitDescription.h"

HabitFinishedDialog::HabitFinishedDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HabitFinishedDialog)
{
    ui->setupUi(this);
    setWindowTitle("Is habit finished?");
}

HabitFinishedDialog::~HabitFinishedDialog()
{
    delete ui;
}

void HabitFinishedDialog::setName(const QString &name)
{
    ui->habitDesc->setName(name);
}

void HabitFinishedDialog::setDeadline(const QString &deadline)
{
    ui->habitDesc->setDeadline(deadline);
}

void HabitFinishedDialog::setPeriod(const QString &period)
{
    ui->habitDesc->setPeriod(period);
}

void HabitFinishedDialog::setAmount(const QString &amount)
{
    ui->habitDesc->setAmount(amount);
}
