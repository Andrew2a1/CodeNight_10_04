#ifndef HABITDESCRIPTION_H
#define HABITDESCRIPTION_H

#include <QWidget>

namespace Ui {
class HabitDescription;
}

class HabitDescription : public QWidget
{
    Q_OBJECT

private:
    Ui::HabitDescription *ui;

public:
    explicit HabitDescription(QWidget *parent = nullptr);
    ~HabitDescription();

    void setName(const QString &name);
    void setDeadline(const QString &deadline);
    void setPeriod(const QString &period);
    void setAmount(const QString &amount);
};

#endif // HABITDESCRIPTION_H
