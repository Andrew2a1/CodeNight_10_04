#include "LoginWidget.h"
#include "ui_LoginWidget.h"

#include "mainwindow.h"
#include "User.h"

#include <QMessageBox>

#include <random>

LoginWidget::LoginWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWidget)
{
    ui->setupUi(this);
    srand(time(NULL));

    if(rand() % 2)
        ui->logo->setPixmap(QPixmap(":/icons/start2.png"));
    else
        ui->logo->setPixmap(QPixmap(":/icons/unistart.png"));
}

LoginWidget::~LoginWidget()
{
    delete ui;
}

void LoginWidget::setMainWindow(MainWindow *mainWindow)
{
    this->mainWindow = mainWindow;
}

void LoginWidget::setDefaultUserName(const QString &username)
{
    ui->userName->setText(username);
}

void LoginWidget::on_loginBtn_clicked()
{
    QString username = ui->userName->text();

    if(username.isEmpty())
        QMessageBox::information(this,
                                 "Error", "Please enter username");
    else
        emit loginPressed(username);
}
