#include "LogoutWidget.h"
#include "ui_LogoutWidget.h"

LogoutWidget::LogoutWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LogoutWidget)
{
    ui->setupUi(this);

    connect(ui->backBtn, &QPushButton::clicked,
            this, &LogoutWidget::backPressed);

    connect(ui->logoutBtn, &QPushButton::clicked,
            this, &LogoutWidget::logoutPressed);
}

LogoutWidget::~LogoutWidget()
{
    delete ui;
}
