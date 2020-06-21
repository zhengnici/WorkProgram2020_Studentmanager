#ifndef UERINFORMWINDOW_H
#define UERINFORMWINDOW_H
#include "user.h"
#include <QDialog>

namespace Ui {
class UerInformWindow;
}

class UerInformWindow : public QDialog
{
    Q_OBJECT
public:
    user loginuser;
public:
    explicit UerInformWindow(QWidget *parent = nullptr);
    ~UerInformWindow();

private:
    Ui::UerInformWindow *ui;
    void DispUerInfor();
signals:
    void UserToAdd();
    void UserToInqure();
private slots:
    void on_pushButton_4_clicked();
    void on_pushButton_3_clicked();
};

#endif // UERINFORMWINDOW_H
