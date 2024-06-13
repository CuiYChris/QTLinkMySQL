#include "mainwidget.h"
#include "ui_mainwidget.h"


MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);

    //禁用窗口最小化最大化按钮
    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    //固定窗口宽度以及高度
    setFixedSize(this->width(),this->height());

    //绑定
    UserDataMode=new QSqlQueryModel(ui->tableView_ListData);

    //调用连接MySQL数据库函数
    QtConnectMySQL();

    //初始化将数据库表中的记录全部显示到tableview控件
    UserDataMode->setQuery("select * from usertables;");
    SelectDBDataInfo();

    //性别点击按钮设置成 选中/取消选中
    ui->radioButton_Male->setAutoExclusive(false);
    ui->radioButton_Female->setAutoExclusive(false);
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::QtConnectMySQL()
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
    db.setHostName("127.0.0.1");//连接本地主机
    db.setPort(3306);//端口号
    db.setDatabaseName("mysqlconnectqtdsc");
    db.setUserName("root");
    db.setPassword("123321");

    bool isconnectedflag=db.open();
    if(!isconnectedflag){
        QMessageBox::critical(this,"Prompt","2-提示: 连接MySQL数据库失败，请重新检查！",
                              QMessageBox::Close);
        //QMessageBox::critical/warning(this,"标题","文本",QMessageBox::Close);
    }
}

void MainWidget::SelectDBDataInfo()//查询数据库中表的信息
{

    UserDataMode->setHeaderData(0,Qt::Horizontal,tr("编号"));
    UserDataMode->setHeaderData(1,Qt::Horizontal,tr("姓名"));
    UserDataMode->setHeaderData(2,Qt::Horizontal,tr("性别"));
    UserDataMode->setHeaderData(3,Qt::Horizontal,tr("部门"));
    UserDataMode->setHeaderData(4,Qt::Horizontal,tr("职务"));

    ui->tableView_ListData->setModel(UserDataMode);
}

//按键控制逻辑
void MainWidget::on_pushButton_add_clicked()
{
    QString strUserID,strUserName,strUserSex,strUserDepartment,strUserJob;

    //给strUserID、strUserName等变量赋值
    strUserID=ui->lineEdit_ID->text();
    strUserName=ui->lineEdit_Name->text();

    if(ui->radioButton_Male->isChecked())//radioButton_Male的QRadioButton控件是否被选中。
    {
        //如果radioButton_Male被选中，将radioButton_Male的文本赋值给变量strUserSex。
        //text()方法返回按钮的显示文本。
        strUserSex=ui->radioButton_Male->text();
    }
    if(ui->radioButton_Female->isChecked())
    {
        strUserSex=ui->radioButton_Female->text();
    }

    strUserDepartment=ui->comboBox_Department->currentText();
    strUserJob=ui->lineEdit_Job->text();

    QSqlQuery QSQLQueryResult;
    //判断用户ID是否为空
    if(strUserID.isEmpty()){
        QMessageBox::critical(this,"prompt","提示：用户ID不能为空，请重新检查！");
        return;
    }
    //判断用户部门是否为空
    if(strUserDepartment=="无"){
        QMessageBox::critical(this,"prompt","提示：用户所属部门不能为空，请重新检查！");
        return;
    }

    //先检查是否存在相同的用户ID
    QString checkSQL=QString("select count(*) from usertables where UserID='%1'")
                           .arg(strUserID);
    QSQLQueryResult.exec(checkSQL);
    if(QSQLQueryResult.next()&&QSQLQueryResult.value(0).toInt()>0){
        QMessageBox::critical(this,"prompt","1-提示：用户ID不能重复，请重新检查！");
        return;
    }

    //将MySQL数据库命令转换成QString字符器
    QString strSQL=QString("insert into usertables(UserID,UserName,UserSex,UserDepartment,UserJob) "
                             "values('%1','%2','%3','%4','%5')")
                             .arg(strUserID)
                             .arg(strUserName)
                             .arg(strUserSex)
                             .arg(strUserDepartment)
                             .arg(strUserJob);

    // 对于SELECT语句，exec()函数会执行查询操作，并将结果集存储在QSqlQuery对象中。
    // 可以使用next()函数遍历结果集，并使用value()函数获取每个字段的值。
    // exec()函数会执行相应的数据库操作并返回一个布尔值表示操作是否成功。
    bool bIsOK = QSQLQueryResult.exec(strSQL);
    if(bIsOK){
        UserDataMode->setQuery("select * from usertables;");
        // 调用查询MySQL数据库中表的记录信息进行显示
        SelectDBDataInfo();
    }
    else{
        QString errorMsg = QSQLQueryResult.lastError().text();
        qDebug()<<"SQL Error："<<errorMsg;
        QMessageBox::critical(this,"prompt","2-提示：用户ID不能重复，请重新检查！");
    }
}

void MainWidget::on_pushButton_delete_clicked()
{
    QSqlQuery query;
    int iCurrentRow = ui->tableView_ListData->currentIndex().row();
    UserDataMode->removeRow(iCurrentRow);

    if(iCurrentRow!=-1)
    {
        int ok = QMessageBox::warning(this,"prompt","提示：你确定真要删除当前选择的记录行吗？",
                                      QMessageBox::Yes,QMessageBox::No);
        //确认删除
        if(ok==QMessageBox::Yes)
        {
            UserDataMode->removeRow(iCurrentRow);
            //获取员工ID
            QString EmptyID=UserDataMode->data(UserDataMode->index(iCurrentRow,0)).toString();
            QString strDelete = "delete from usertables where UserID='" + EmptyID + "';";
            query.exec(strDelete);
            UserDataMode->setQuery("select * from usertables;");
            ui->tableView_ListData->setModel(UserDataMode);
            QMessageBox::information(this, "Prompt", "提示：恭喜你删除记录信息成功！",QMessageBox::Close);
            SelectDBDataInfo();
        }
    }
    else
    {
        QMessageBox::warning(this, "Prompt", "提示：请选择要删除的记录信息？",QMessageBox::Yes);
    }
}

void MainWidget::on_pushButton_select_clicked()
{
    QString strUserID,strUserName,strUserSex,strUserDepartment,strUserJob;

    strUserID=ui->lineEdit_ID->text();
    strUserName=ui->lineEdit_Name->text();
    if(ui->radioButton_Male->isChecked()){strUserSex=ui->radioButton_Male->text();}
    if(ui->radioButton_Female->isChecked()){strUserSex=ui->radioButton_Female->text();}
    strUserDepartment=ui->comboBox_Department->currentText();
    strUserJob=ui->lineEdit_Job->text();

    QString strSQL = QString("select * from usertables where 1=1");

    //根据用户ID筛选
    if(!strUserID.isEmpty()){
        strSQL += QString(" and UserID = '%1'").arg(strUserID);
    }
    //根据用户姓名筛选
    if(!strUserName.isEmpty()){
        strSQL += QString(" and UserName like '%%1'").arg(strUserName);
    }
    //根据性别筛选
    if(!strUserSex.isEmpty()){
        strSQL += QString(" and UserSex = '%1'").arg(strUserSex);
    }
    //根据部门筛选
    if(!strUserDepartment.isEmpty()&&strUserDepartment!="无"){
        strSQL += QString(" and UserDepartment = '%1'").arg(strUserDepartment);
    }
    //根据职务筛选
    if(!strUserJob.isEmpty()){
        strSQL += QString(" and UserJob like '%%1'").arg(strUserJob);
    }

    UserDataMode->setQuery(strSQL);
    SelectDBDataInfo();
}

void MainWidget::on_pushButton_modify_clicked()
{
    QSqlQuery query;
    QString str="update usertables set UserName = '"+ui->lineEdit_Name->text()+
                "'where UserID='"+ui->lineEdit_ID->text()+"';";
    query.exec(str);
    QMessageBox::information(this,"prompt","提示：恭喜你修改信息成功！",QMessageBox::Close);
    UserDataMode->setQuery("select * from usertables;");
    SelectDBDataInfo();
}

void MainWidget::on_pushButton_Home_clicked()
{
    //初始化将数据库表中的记录全部显示到tableview控件
    UserDataMode->setQuery("select * from usertables;");
    SelectDBDataInfo();
}

void MainWidget::on_tableView_ListData_pressed(const QModelIndex &index)
{
    Public_strID=UserDataMode->data(UserDataMode->index(index.row(),0)).toString();
    QString strName=UserDataMode->data(UserDataMode->index(index.row(),1)).toString();

    //性别处理
    QString strSexs=UserDataMode->data(UserDataMode->index(index.row(),2)).toString();
    if(strSexs=="男"){
        ui->radioButton_Male->setChecked(true);
    }
    if(strSexs=="女"){
        ui->radioButton_Female->setChecked(true);
    }

    //部门处理
    QString strDpts=UserDataMode->data(UserDataMode->index(index.row(),3)).toString();
    for(int i=0;i<ui->comboBox_Department->count();i++)
    {
        QString strTemp=ui->comboBox_Department->itemText(i);
        if(strDpts==strTemp)
        {
            ui->comboBox_Department->setCurrentText(strTemp);
        }
    }

    QString strJob=UserDataMode->data(UserDataMode->index(index.row(),4)).toString();

    ui->lineEdit_ID->setText(Public_strID);
    ui->lineEdit_Name->setText(strName);
    ui->lineEdit_Job->setText(strJob);
}
