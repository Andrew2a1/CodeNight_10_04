#ifndef MAINAPPWIDGET_H
#define MAINAPPWIDGET_H

#include <QWidget>

namespace Ui {
class MainAppWidget;
}

class MainAppWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainAppWidget(QWidget *parent = nullptr);
    ~MainAppWidget();

private:
    Ui::MainAppWidget *ui;
};

#endif // MAINAPPWIDGET_H
