#ifndef STUDYMODEWIDGET_H
#define STUDYMODEWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QTime>

namespace Ui {
class StudyModeWidget;
}

class StudyModeWidget : public QWidget
{
    Q_OBJECT

private:
    Ui::StudyModeWidget *ui;
    QTimer *refreshTimer;
    QDateTime endTime;
    bool isInStudyMode = false;

public:
    explicit StudyModeWidget(QWidget *parent = nullptr);
    ~StudyModeWidget();

    bool inStudyMode();
    void askAboutTime();

public slots:
    void refreshTime();

signals:
    void returnPressed();
    void studyModePassed(int mark);

};

#endif // STUDYMODEWIDGET_H
