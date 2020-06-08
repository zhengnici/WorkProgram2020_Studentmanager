#ifndef INQUREWINDOW_H
#define INQUREWINDOW_H

#include <QDialog>

namespace Ui {
class inqureWindow;
}

class inqureWindow : public QDialog
{
    Q_OBJECT

public:
    explicit inqureWindow(QWidget *parent = nullptr);
    ~inqureWindow();

private:
    Ui::inqureWindow *ui;
};

#endif // INQUREWINDOW_H
