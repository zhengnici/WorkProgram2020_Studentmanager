#include "filebrowser.h"
#include "ui_filebrowser.h"

void FileBrowser::init()
{
        model = new QFileSystemModel();

        model->setRootPath("d:/");
        QStringList nameFilter;
        nameFilter << "*.csv" ;//可添加<< "*.h"实现多文件格式
        model->setNameFilterDisables(false);
        model->setNameFilters(nameFilter);
        ui->treeView->setModel(model);
        ui->treeView->setRootIndex(model->index("D:/program"));
}

FileBrowser::FileBrowser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FileBrowser)
{
    ui->setupUi(this);
    init();
}

FileBrowser::~FileBrowser()
{
    delete ui;
}

void FileBrowser::on_pushButton_2_clicked()
{
    if(filepath.indexOf(".csv")>=0)
    {
        emit ObjPath(filepath);
        this->hide();
    }
    else
    {
        QMessageBox::information(NULL, "错误", "未选择正确文件只支持CSV格式文件");
    }
}

void FileBrowser::on_treeView_clicked(const QModelIndex &index)
{
    filepath.clear();
    filepath=model->filePath(index);
}

void FileBrowser::on_pushButton_clicked()
{
    this->hide();
}
