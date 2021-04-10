#include "MainAppWidget.h"
#include "ui_MainAppWidget.h"

#include <QLabel>
#include <QVBoxLayout>


MainAppWidget::MainAppWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainAppWidget)
{
    ui->setupUi(this);
}

MainAppWidget::~MainAppWidget()
{
    delete ui;
    delete user;
}

void MainAppWidget::setUser(User *user)
{
    this->user = user;
    ui->helloLabel->setText("Witaj " + user->getName());
}
