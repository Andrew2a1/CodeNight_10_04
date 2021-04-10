#ifndef ADDHABITWIDGET_H
#define ADDHABITWIDGET_H

#include <QWidget>

namespace Ui {
class AddHabitWidget;
}

class AddHabitWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AddHabitWidget(QWidget *parent = nullptr);
    ~AddHabitWidget();

private:
    Ui::AddHabitWidget *ui;
};

#endif // ADDHABITWIDGET_H
