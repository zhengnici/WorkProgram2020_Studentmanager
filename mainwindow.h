#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "studentqt.h"
#include "inqurewindow.h"
#include <QMainWindow>
#include <string>
#include <QStringListModel>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:     //user class and function
    studentQT Opera_studens1;//学生成员变量



public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:


private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
