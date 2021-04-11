#ifndef POWERBAR_H
#define POWERBAR_H

#include <QProgressBar>

class PowerBar : public QProgressBar
{
    Q_OBJECT

public:
    PowerBar(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // POWERBAR_H
