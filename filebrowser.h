#ifndef FILEBROWSER_H
#define FILEBROWSER_H

#include <QDialog>
#include <QFileSystemModel>
#include <QApplication>
#include <QDir>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class FileBrowser;
}

class FileBrowser : public QDialog
{
    Q_OBJECT
public:
    void init();
    QString filepath;
public:
    explicit FileBrowser(QWidget *parent = nullptr);
    ~FileBrowser();

private slots:
    void on_pushButton_2_clicked();

    void on_treeView_clicked(const QModelIndex &index);

    void on_pushButton_clicked();

private:
    Ui::FileBrowser *ui;
    QFileSystemModel *model;
signals:
    void ObjPath(QString);
};

#endif // FILEBROWSER_H
