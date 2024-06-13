/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QGroupBox *groupBox;
    QTableView *tableView_ListData;
    QGroupBox *groupBox_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit_ID;
    QLineEdit *lineEdit_Name;
    QLineEdit *lineEdit_Job;
    QComboBox *comboBox_Department;
    QRadioButton *radioButton_Male;
    QRadioButton *radioButton_Female;
    QGroupBox *groupBox_3;
    QPushButton *pushButton_modify;
    QPushButton *pushButton_delete;
    QPushButton *pushButton_select;
    QPushButton *pushButton_add;
    QPushButton *pushButton_Home;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName("MainWidget");
        MainWidget->resize(921, 450);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Images/logo.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWidget->setWindowIcon(icon);
        MainWidget->setStyleSheet(QString::fromUtf8(""));
        groupBox = new QGroupBox(MainWidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 10, 571, 431));
        tableView_ListData = new QTableView(groupBox);
        tableView_ListData->setObjectName("tableView_ListData");
        tableView_ListData->setGeometry(QRect(10, 20, 551, 401));
        groupBox_2 = new QGroupBox(MainWidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(600, 10, 311, 261));
        QFont font;
        font.setPointSize(12);
        groupBox_2->setFont(font);
        groupBox_2->setAlignment(Qt::AlignCenter);
        label = new QLabel(groupBox_2);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 30, 61, 31));
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 80, 61, 31));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 120, 61, 41));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 170, 61, 41));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 220, 61, 31));
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignCenter);
        lineEdit_ID = new QLineEdit(groupBox_2);
        lineEdit_ID->setObjectName("lineEdit_ID");
        lineEdit_ID->setGeometry(QRect(70, 30, 231, 31));
        lineEdit_Name = new QLineEdit(groupBox_2);
        lineEdit_Name->setObjectName("lineEdit_Name");
        lineEdit_Name->setGeometry(QRect(70, 80, 231, 31));
        lineEdit_Job = new QLineEdit(groupBox_2);
        lineEdit_Job->setObjectName("lineEdit_Job");
        lineEdit_Job->setGeometry(QRect(70, 220, 231, 31));
        comboBox_Department = new QComboBox(groupBox_2);
        comboBox_Department->addItem(QString());
        comboBox_Department->addItem(QString());
        comboBox_Department->addItem(QString());
        comboBox_Department->addItem(QString());
        comboBox_Department->addItem(QString());
        comboBox_Department->addItem(QString());
        comboBox_Department->addItem(QString());
        comboBox_Department->addItem(QString());
        comboBox_Department->addItem(QString());
        comboBox_Department->addItem(QString());
        comboBox_Department->setObjectName("comboBox_Department");
        comboBox_Department->setGeometry(QRect(80, 180, 211, 31));
        radioButton_Male = new QRadioButton(groupBox_2);
        radioButton_Male->setObjectName("radioButton_Male");
        radioButton_Male->setGeometry(QRect(107, 124, 61, 41));
        radioButton_Male->setMaximumSize(QSize(16777215, 16777215));
        radioButton_Male->setFont(font);
        radioButton_Male->setStyleSheet(QString::fromUtf8("QRadioButton::indicator {\n"
"    width: 14px;\n"
"    height: 14px;\n"
"}"));
        radioButton_Male->setIconSize(QSize(20, 20));
        radioButton_Female = new QRadioButton(groupBox_2);
        radioButton_Female->setObjectName("radioButton_Female");
        radioButton_Female->setGeometry(QRect(210, 130, 51, 31));
        radioButton_Female->setMaximumSize(QSize(16777215, 16777215));
        radioButton_Female->setFont(font);
        radioButton_Female->setStyleSheet(QString::fromUtf8("QRadioButton::indicator {\n"
"    width: 14px;\n"
"    height: 14px;\n"
"}"));
        radioButton_Female->setIconSize(QSize(20, 20));
        groupBox_3 = new QGroupBox(MainWidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(600, 280, 311, 161));
        pushButton_modify = new QPushButton(groupBox_3);
        pushButton_modify->setObjectName("pushButton_modify");
        pushButton_modify->setGeometry(QRect(200, 110, 101, 41));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Images/excel.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_modify->setIcon(icon1);
        pushButton_delete = new QPushButton(groupBox_3);
        pushButton_delete->setObjectName("pushButton_delete");
        pushButton_delete->setGeometry(QRect(200, 10, 101, 41));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Images/NO.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_delete->setIcon(icon2);
        pushButton_select = new QPushButton(groupBox_3);
        pushButton_select->setObjectName("pushButton_select");
        pushButton_select->setGeometry(QRect(10, 110, 111, 41));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Images/SELECT.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_select->setIcon(icon3);
        pushButton_add = new QPushButton(groupBox_3);
        pushButton_add->setObjectName("pushButton_add");
        pushButton_add->setGeometry(QRect(10, 10, 111, 41));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Images/OK.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_add->setIcon(icon4);
        pushButton_Home = new QPushButton(groupBox_3);
        pushButton_Home->setObjectName("pushButton_Home");
        pushButton_Home->setGeometry(QRect(130, 50, 68, 68));
        pushButton_Home->setStyleSheet(QString::fromUtf8("border-radius:34px;\n"
"border-width:1px;\n"
"border-style:solid;\n"
"border-color:black;"));

        retranslateUi(MainWidget);

        comboBox_Department->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QCoreApplication::translate("MainWidget", "\346\225\260\346\215\256\345\272\223\347\224\250\346\210\267\347\263\273\347\273\237", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWidget", "\347\224\250\346\210\267\345\210\227\350\241\250", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWidget", "\344\277\241\346\201\257", nullptr));
        label->setText(QCoreApplication::translate("MainWidget", "\347\274\226\345\217\267\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("MainWidget", "\345\247\223\345\220\215\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("MainWidget", "\346\200\247\345\210\253\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("MainWidget", "\351\203\250\351\227\250\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("MainWidget", "\350\201\214\345\212\241\357\274\232", nullptr));
        comboBox_Department->setItemText(0, QCoreApplication::translate("MainWidget", "\346\227\240", nullptr));
        comboBox_Department->setItemText(1, QCoreApplication::translate("MainWidget", "\347\240\224\345\217\221\351\203\250", nullptr));
        comboBox_Department->setItemText(2, QCoreApplication::translate("MainWidget", "\347\274\226\350\276\221\351\203\250", nullptr));
        comboBox_Department->setItemText(3, QCoreApplication::translate("MainWidget", "\351\224\200\345\224\256\351\203\250", nullptr));
        comboBox_Department->setItemText(4, QCoreApplication::translate("MainWidget", "\346\212\200\346\234\257\351\203\250", nullptr));
        comboBox_Department->setItemText(5, QCoreApplication::translate("MainWidget", "\344\272\247\345\223\201\351\203\250", nullptr));
        comboBox_Department->setItemText(6, QCoreApplication::translate("MainWidget", "\350\277\220\350\220\245\351\203\250", nullptr));
        comboBox_Department->setItemText(7, QCoreApplication::translate("MainWidget", "\350\256\276\350\256\241\351\203\250", nullptr));
        comboBox_Department->setItemText(8, QCoreApplication::translate("MainWidget", "\350\264\242\345\212\241\351\203\250", nullptr));
        comboBox_Department->setItemText(9, QCoreApplication::translate("MainWidget", "\344\272\272\345\212\233\350\265\204\346\272\220\351\203\250", nullptr));

        comboBox_Department->setCurrentText(QCoreApplication::translate("MainWidget", "\346\227\240", nullptr));
        radioButton_Male->setText(QCoreApplication::translate("MainWidget", "\347\224\267", nullptr));
        radioButton_Female->setText(QCoreApplication::translate("MainWidget", "\345\245\263", nullptr));
        groupBox_3->setTitle(QString());
        pushButton_modify->setText(QCoreApplication::translate("MainWidget", "\344\277\256\346\224\271\347\224\250\346\210\267", nullptr));
        pushButton_delete->setText(QCoreApplication::translate("MainWidget", "\345\210\240\351\231\244\347\224\250\346\210\267", nullptr));
        pushButton_select->setText(QCoreApplication::translate("MainWidget", "\346\237\245\350\257\242\347\224\250\346\210\267", nullptr));
        pushButton_add->setText(QCoreApplication::translate("MainWidget", "\346\267\273\345\212\240\347\224\250\346\210\267", nullptr));
        pushButton_Home->setText(QCoreApplication::translate("MainWidget", "Home", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
