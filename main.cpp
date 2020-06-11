#include "mainwindow.h"
#include <QApplication>
#include "sqliteOperat.h"

void myinit(void);
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

