#include "mainwindow.h"

#include <QStyleFactory>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle(QStyleFactory::create("fusion"));

    MainWindow w;
    w.show();
    w.setFixedSize(1440/3, 2960/3);

    return a.exec();
}
