#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "studentqt.h"
#include "inqurewindow.h"
#include "addstudentwindw.h"
#include "loginaccount.h"
#include <QMainWindow>
#include <string>
#include <QStringListModel>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:     //user class and function


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:


    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    AddStudentWindw w;
    LoginAccount UserAccount;

};

#endif // MAINWINDOW_H
