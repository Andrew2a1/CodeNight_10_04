#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>

class MainWindow;

namespace Ui {
class LoginWidget;
}

class LoginWidget : public QWidget
{
    Q_OBJECT

private:
    MainWindow *mainWindow = nullptr;

public:
    explicit LoginWidget(QWidget *parent = nullptr);
    ~LoginWidget();

    void setMainWindow(MainWindow *mainWindow);
    void setDefaultUserName(const QString &username);

private slots:
    void on_loginBtn_clicked();

private:
    Ui::LoginWidget *ui;
};

#endif // LOGINWIDGET_H
