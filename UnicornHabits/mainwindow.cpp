#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    loginWidget = new LoginWidget(this);
    loginWidget->setMainWindow(this);

    setCentralWidget(loginWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::switchToMainWidget()
{
    if(loginWidget) {
        loginWidget->deleteLater();
        loginWidget = nullptr;
    }

    if(!mainWidget)
        mainWidget = new MainAppWidget(this);

    setCentralWidget(mainWidget);
}

