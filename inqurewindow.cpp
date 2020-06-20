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

//修改某一列
void inqureWindow::on_pushButton_5_clicked()
{
    sqlmodel->database().transaction(); //开始事务操作
    if (sqlmodel->submitAll()) {
        sqlmodel->database().commit(); //提交
    } else {
        sqlmodel->database().rollback(); //回滚
        QMessageBox::warning(this, tr("tableModel"),
                             tr("数据库错误: %1")
                             .arg(sqlmodel->lastError().text()));
    }
}

//删除某一列
void inqureWindow::on_pushButton_7_clicked()
{
    int curRow = ui->tableView->currentIndex().row();
     //获取选中的行
     sqlmodel->removeRow(curRow);
     //删除该行
     int ok = QMessageBox::warning(this,tr("删除当前行!"),tr("你确定"
                                                            "删除当前行吗？"),
                          QMessageBox::Yes,QMessageBox::No);
     if(ok == QMessageBox::No)
     {
        sqlmodel->revertAll(); //如果不删除，则撤销
     }
     else sqlmodel->submitAll(); //否则提交，在数据库中删除该行
}

void inqureWindow::on_pushButton_6_clicked()
{
    QString provi=ui->comboBox_2->currentText();
    QRegExp rx;//正则表达式
    rx.setPatternSyntax(QRegExp::RegExp);
    rx.setPattern(QString("^四川+$"));//设置表达式条件

    switch(ui->comboBox_2->currentIndex())
    {
    case 0:
    {//无约束条件
        if(ui->lineEdit->text().isEmpty())
        {
            sqlmodel->setTable("students");//选择数据库的表
            sqlmodel->setEditStrategy(QSqlTableModel::OnManualSubmit);
            sqlmodel->select();//相当于刷新整个表
        }
        else
        {
            switch (ui->comboBox->currentIndex())
            {
            case 0: {QString id = ui->lineEdit->text();
                sqlmodel->setFilter(QObject::tr("id = '%1'").arg(id)); //根据学号进行筛选
                sqlmodel->select(); break;}//显示结果
            case 1: { QString name = ui->lineEdit->text();
                sqlmodel->setFilter(QObject::tr("name = '%1'").arg(name)); //根据姓名进行筛选
                sqlmodel->select(); break;}//显示结果
            }
        } break;
    }
    case 1:
    {//四川省
        if(ui->lineEdit->text().isEmpty())
        {
            sqlmodel->setEditStrategy(QSqlTableModel::OnManualSubmit);
             sqlmodel->setFilter(QObject::tr("province='%1'").arg("四川省"));
            sqlmodel->select();//相当于刷新只含四川的
        }
        else
        {
            switch (ui->comboBox->currentIndex())
            {
            case 0: {QString id = ui->lineEdit->text();
                sqlmodel->setFilter(QObject::tr("id = '%1' and province='%2'").arg(id).arg(provi)); //根据学号和四川籍进行筛选
                sqlmodel->select(); break;}//显示结果
            case 1: { QString name = ui->lineEdit->text();
                sqlmodel->setFilter(QObject::tr("name = '%1'and province='%2'").arg(name).arg(provi)); //根据姓名和四川籍进行筛选
                sqlmodel->select(); break;}//显示结果
            }
        } break;
    }
    case 2:
    {//其它省份
        if(ui->lineEdit->text().isEmpty())
        {
            sqlmodel->setEditStrategy(QSqlTableModel::OnManualSubmit);
            sqlmodel->setFilter(QObject::tr("province<>'%1'").arg("四川省"));
            sqlmodel->select();//相当于刷新整个表
        }
        else
        {
            switch (ui->comboBox->currentIndex())
            {
            case 0: {QString id = ui->lineEdit->text();
                sqlmodel->setFilter(QObject::tr("id = '%1' and province<>'%2'").arg(id).arg("四川省")); //根据学号和非四川籍进行筛选
                sqlmodel->select(); break;}//显示结果
            case 1: { QString name = ui->lineEdit->text();
                sqlmodel->setFilter(QObject::tr("name = '%1and province<>'%2'").arg(name).arg(provi)); //根据姓名和非四川籍进行筛选
                sqlmodel->select(); break;}//显示结果
            }
        } break;
    }
}
}

void inqureWindow::on_pushButton_8_clicked()
{

}
