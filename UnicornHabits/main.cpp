#include "mainwindow.h"

#include <QStyleFactory>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle(QStyleFactory::create("fusion"));

    MainWindow w;
    w.show();
    w.resize(450, 800);

    return a.exec();
}
