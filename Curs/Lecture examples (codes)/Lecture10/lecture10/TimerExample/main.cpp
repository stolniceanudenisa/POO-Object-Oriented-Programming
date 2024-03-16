#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AlarmWidget w;
    w.showMinimized();
    return a.exec();
}
