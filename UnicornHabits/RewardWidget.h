#ifndef REWARDWIDGET_H
#define REWARDWIDGET_H

#include <QWidget>

namespace Ui {
class RewardWidget;
}

class RewardWidget : public QWidget
{
    Q_OBJECT

private:
    Ui::RewardWidget *ui;

public:
    explicit RewardWidget(QWidget *parent = nullptr);
    ~RewardWidget();

signals:
    void returnPressed();

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // REWARDWIDGET_H
