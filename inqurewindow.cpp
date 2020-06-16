#include "inqurewindow.h"
#include "ui_inqurewindow.h"


inqureWindow::inqureWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inqureWindow)
{
    ui->setupUi(this);
    InitiaTableView();

}

inqureWindow::~inqureWindow()
{
    delete ui;
}

void inqureWindow::on_pushButton_4_clicked()
{
    emit mySignal();//发出切换信号到添加窗口的槽中
}


//初始化tableview的标题
void inqureWindow::InitiaTableView()
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE","tableViewconntosqlite");
    db.setDatabaseName(QApplication::applicationDirPath()+"/StudentDataBase.db");

    if(db.open())
    {
        QSqlQuery sql_query(db);
        sqlmodel = new QSqlTableModel(this,db);//ui->tableView
        sqlmodel->setTable("students");//选择数据库的表

        sqlmodel->setEditStrategy(QSqlTableModel::OnManualSubmit);
        sqlmodel->select(); //选取整个表的所有行
        // model->removeColumn(1); //不显示name属性列,如果这时添加记录，则该属性的值添加不上
        ui->tableView->setModel(sqlmodel);
        // ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);   //使其不可编辑
        ui->tableView->setModel(sqlmodel);
    }
    else
    {
       qDebug()<<"SQlite not open in fun InitiaTableView()";
    }



}

