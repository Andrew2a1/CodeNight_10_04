#ifndef LOGOUTWIDGET_H
#define LOGOUTWIDGET_H

#include <QWidget>

namespace Ui {
class LogoutWidget;
}

class LogoutWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LogoutWidget(QWidget *parent = nullptr);
    ~LogoutWidget();

signals:
    void logoutPressed();
    void backPressed();

protected:
    void paintEvent(QPaintEvent *event);

private:
    Ui::LogoutWidget *ui;
};

#endif // LOGOUTWIDGET_H
