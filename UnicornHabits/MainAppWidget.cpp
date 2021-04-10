#include "MainAppWidget.h"
#include "ui_MainAppWidget.h"

#include <QLabel>
#include <QVBoxLayout>


MainAppWidget::MainAppWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainAppWidget)
{
    ui->setupUi(this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *label = new QLabel("Hello", this);

    layout->addWidget(label);
}

MainAppWidget::~MainAppWidget()
{
    delete ui;
}
