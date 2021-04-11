#include "LoginWidget.h"
#include "ui_LoginWidget.h"

#include "mainwindow.h"
#include "User.h"

#include <QMessageBox>

LoginWidget::LoginWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWidget)
{
    ui->setupUi(this);
    ui->logo->load(QString(":/icons/UnicornHabitsIcon.SVG"));
    ui->gridLayout->setAlignment(ui->logo, Qt::AlignCenter);
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
