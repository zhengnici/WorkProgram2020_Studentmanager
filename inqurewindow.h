#ifndef INQUREWINDOW_H
#define INQUREWINDOW_H
#include "studentqt.h"
#include "filebrowser.h"
#include <QFileDialog>
#include <QDialog>
#include <QTableView>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QObject>
#include <QSqlTableModel>
#include <QStandardItemModel>
#include <QMessageBox>
#include <QSqlRecord>

namespace Ui {
class inqureWindow;
}

class inqureWindow : public QDialog
{
    Q_OBJECT
public:     //user class and function
    QString objpath;
    void ReadforDataBase(QString dbname);
private:
    void OutOut();
public:
    explicit inqureWindow(QWidget *parent = nullptr);
    ~inqureWindow();

private slots:

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_2_clicked();



private:
    Ui::inqureWindow *ui;
    void InitiaTableView(void);
    studentQT Opera_studens2;//学生成员变量
    QSqlTableModel *sqlmodel;//SQL模型
    FileBrowser w1;
signals:
    void InqureToAdd();//切换到信息添加界面
    void InqureToUser();//切换到用户信息界面
};

#endif // INQUREWINDOW_H
