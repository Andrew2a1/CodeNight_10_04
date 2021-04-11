#include "LogoutWidget.h"
#include "ui_LogoutWidget.h"

#include <QPainter>
#include <QPaintEvent>
#include <QPainterPath>

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

void LogoutWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap(":/icons/settings.png"));
    QWidget::paintEvent(event);
}
