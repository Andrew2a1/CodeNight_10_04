#ifndef MAINAPPWIDGET_H
#define MAINAPPWIDGET_H

#include <QWidget>
#include "User.h"

namespace Ui {
class MainAppWidget;
}

class MainAppWidget : public QWidget
{
    Q_OBJECT

private:
    User *user = nullptr;

public:
    explicit MainAppWidget(QWidget *parent = nullptr);
    ~MainAppWidget();

    void setUser(User *user);

private:
    Ui::MainAppWidget *ui;
};

#endif // MAINAPPWIDGET_H
