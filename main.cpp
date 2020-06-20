#include "mainwindow.h"
#include "addstudentwindw.h"
#include <QApplication>


void myinit(void);
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow mw;
    mw.show();
    AddStudentWindw w;
    w.show();

    return a.exec();
}

