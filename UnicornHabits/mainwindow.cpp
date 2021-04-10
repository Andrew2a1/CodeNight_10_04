#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    switchToLoginWidget();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::switchToMainWidget(User *user)
{
    if(loginWidget) {
        loginWidget->deleteLater();
        loginWidget = nullptr;
    }

    if(!mainWidget) {
        mainWidget = new MainAppWidget(this);
        mainWidget->setUser(user);
    }

    setCentralWidget(mainWidget);
}

void MainWindow::switchToLoginWidget(const QString &lastUserName)
{
    loginWidget = new LoginWidget(this);
    loginWidget->setMainWindow(this);
    loginWidget->setDefaultUserName(lastUserName);

    setCentralWidget(loginWidget);
}
