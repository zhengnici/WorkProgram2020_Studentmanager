#include "mainwindow.h"
#include "addstudentwindw.h"
#include <QApplication>


void myinit(void);
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AddStudentWindw w;
    w.show();
    //MainWindow w;
    //w.show();

    return a.exec();
}

