#include "mainwindow.h"

#include <QStyleFactory>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle(QStyleFactory::create("fusion"));

    MainWindow w;
    w.setFixedSize(1440/3, 2960/3);
    w.setWindowTitle("UnicornHabits");
    w.setWindowIcon(QIcon(":/icons/UnicornHabitsIcon.SVG"));
    w.show();

    return a.exec();
}
