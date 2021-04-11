#include "StudyModeWidget.h"
#include "ui_StudyModeWidget.h"

#include <QLabel>
#include <QSpinBox>

#include <QDialog>
#include <QDialogButtonBox>
#include <QFormLayout>

#include <QTime>
#include <QDateTime>

#include <QPainter>
#include <QMessageBox>

StudyModeWidget::StudyModeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudyModeWidget)
{
    ui->setupUi(this);
    refreshTimer = new QTimer(this);
    refreshTimer->setInterval(500);
    refreshTimer->setSingleShot(false);

    connect(refreshTimer, &QTimer::timeout,
            this, &StudyModeWidget::refreshTime);

    connect(ui->returnBtn, &QPushButton::clicked,
            this, &StudyModeWidget::returnToMain);
}

void StudyModeWidget::returnToMain()
{
    QMessageBox::StandardButton reply;

    reply = QMessageBox::question(this,
                                  "Stop study mode?",
                                  "Do you really want to exit?"
                                  " You will lost some points :(",
                                  QMessageBox::Yes|QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        isInStudyMode = false;
        refreshTimer->stop();
        emit studyModePassed(-1);
    }
}

StudyModeWidget::~StudyModeWidget()
{
    delete ui;
}

bool StudyModeWidget::inStudyMode()
{
    return isInStudyMode;
}

void StudyModeWidget::askAboutTime()
{
    QDialog dialog(this);
    QFormLayout form(&dialog);

    form.addRow(new QLabel("Please specify the time:"));

    QSpinBox *hours = new QSpinBox(&dialog);
    hours->setRange(0, 23);

    QSpinBox *minutes = new QSpinBox(&dialog);
    minutes->setRange(0, 59);

    QSpinBox *seconds = new QSpinBox(&dialog);
    seconds->setRange(0, 59);

    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                               Qt::Horizontal, &dialog);

    form.addRow("Hours:", hours);
    form.addRow("Minutes:", minutes);
    form.addRow("Seconds:", seconds);
    form.addRow(&buttonBox);

    QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
    QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));

    if (dialog.exec() == QDialog::Accepted)
    {
        QDateTime startTime = QDateTime::currentDateTime();
        endTime = startTime.addSecs(seconds->value() +
                                    minutes->value()*60 +
                                    hours->value()*3600);

        isInStudyMode = true;
        refreshTimer->start();
    }
    else
    {
        emit returnPressed();
    }
}

void StudyModeWidget::refreshTime()
{
    int timeLeft = QDateTime::currentDateTime().msecsTo(endTime);

    ui->timeEdit->setTime(QTime::fromMSecsSinceStartOfDay(timeLeft));

    if(timeLeft <= 0)
    {
        isInStudyMode = false;
        refreshTimer->stop();
        emit studyModePassed(1);
    }
}

void StudyModeWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap(":/icons/study.png"));
    QWidget::paintEvent(event);
}

