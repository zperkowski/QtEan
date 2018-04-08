#include "mainwindow.h"
#include <QApplication>
#include <stdio.h>
#include "interval.h"

using namespace interval_arithmetic;

int main(int argc, char *argv[]) {
    QInternal interval;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
