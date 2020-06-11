#ifndef INQUREWINDOW_H
#define INQUREWINDOW_H
#include "studentqt.h"
#include <QDialog>

namespace Ui {
class inqureWindow;
}

class inqureWindow : public QDialog
{
    Q_OBJECT
public:     //user class and function
    studentQT Opera_studens1;//学生成员变量

public:
    explicit inqureWindow(QWidget *parent = nullptr);
    ~inqureWindow();

private:
    Ui::inqureWindow *ui;
};

#endif // INQUREWINDOW_H
