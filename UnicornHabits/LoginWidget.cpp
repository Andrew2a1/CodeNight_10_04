#include "LoginWidget.h"
#include "ui_LoginWidget.h"

#include "mainwindow.h"

LoginWidget::LoginWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWidget)
{
    ui->setupUi(this);
}

LoginWidget::~LoginWidget()
{
    delete ui;
}

void LoginWidget::setMainWindow(MainWindow *mainWindow)
{
    this->mainWindow = mainWindow;
}

void LoginWidget::on_loginBtn_clicked()
{
    if(mainWindow)
        mainWindow->switchToMainWidget();
}
