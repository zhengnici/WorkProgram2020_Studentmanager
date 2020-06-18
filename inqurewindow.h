#ifndef INQUREWINDOW_H
#define INQUREWINDOW_H
#include "studentqt.h"
#include <QDialog>
#include <QTableView>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QObject>
#include <QSqlTableModel>
#include <QStandardItemModel>
#include <QMessageBox>

namespace Ui {
class inqureWindow;
}

class inqureWindow : public QDialog
{
    Q_OBJECT
public:     //user class and function

    void ReadforDataBase(QString dbname);
public:
    explicit inqureWindow(QWidget *parent = nullptr);
    ~inqureWindow();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::inqureWindow *ui;
    void InitiaTableView(void);
    studentQT Opera_studens2;//学生成员变量
    QSqlTableModel *sqlmodel;
signals:
    void mySignal();//自定义信号，与界面切换有关
};

#endif // INQUREWINDOW_H
