#include "AddHabitWidget.h"
#include "ui_AddHabitWidget.h"

AddHabitWidget::AddHabitWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddHabitWidget)
{
    ui->setupUi(this);
}

AddHabitWidget::~AddHabitWidget()
{
    delete ui;
}
