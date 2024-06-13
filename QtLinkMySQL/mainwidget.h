#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlError>
#include<QSqlQueryModel>
#include<QMessageBox>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWidget;
}
QT_END_NAMESPACE

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

public:
    //自定义函数
    void QtConnectMySQL();//Qt连接MySQL数据库
    void SelectDBDataInfo();//查询MySQL数据库中表的记录信息

    QSqlDatabase db;//定义数据库对象
    QSqlQueryModel *UserDataMode;//数据模型

    QString Public_strID;

private slots:
    //私有槽函数（private slots）
    //定义：私有槽函数是槽函数的一种访问级别，定义为私有意味着这些函数只能被类的内部成员访问，
    //不能被外部对象直接调用。
    //用途：专门用来处理信号。这些函数会在连接了相应信号时自动被调用。
    //定义为私有槽函数，通常是因为这些槽只在类的内部使用。
    void on_pushButton_add_clicked();
    void on_pushButton_delete_clicked();
    void on_pushButton_select_clicked();
    void on_pushButton_modify_clicked();
    void on_pushButton_Home_clicked();


    void on_tableView_ListData_pressed(const QModelIndex &index);

private:
    Ui::MainWidget *ui;
};
#endif // MAINWIDGET_H
