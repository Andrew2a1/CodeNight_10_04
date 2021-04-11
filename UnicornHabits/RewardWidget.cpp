#include "RewardWidget.h"
#include "ui_RewardWidget.h"

#include <QPainter>

RewardWidget::RewardWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RewardWidget)
{
    ui->setupUi(this);

    connect(ui->returnButton, &QPushButton::clicked,
            this, &RewardWidget::returnPressed);
}

RewardWidget::~RewardWidget()
{
    delete ui;
}

void RewardWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap(":/icons/rewards.png"));
    QWidget::paintEvent(event);
}
