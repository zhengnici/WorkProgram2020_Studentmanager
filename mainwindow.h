#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "studentqt.h"
#include <string>
#include <QStringListModel>
#include "inqurewindow.h"

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

    void on_pushButton_6_clicked(bool checked);

    void on_pushButton_3_clicked(bool checked);

private:
    Ui::MainWindow *ui;
    inqureWindow w1;

};

#endif // MAINWINDOW_H
