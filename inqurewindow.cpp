#include "inqurewindow.h"
#include "ui_inqurewindow.h"

inqureWindow::inqureWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inqureWindow)
{
    ui->setupUi(this);
}

inqureWindow::~inqureWindow()
{
    delete ui;
}
