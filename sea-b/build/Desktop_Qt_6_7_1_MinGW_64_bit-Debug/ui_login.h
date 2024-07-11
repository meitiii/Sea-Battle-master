/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QLabel *label;
    QLineEdit *userLine;
    QLineEdit *PassLine;
    QPushButton *LogButt;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(468, 455);
        label = new QLabel(Login);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 451, 441));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/Pictures/BackGround/paper.png);\n"
"border-radius:30px;"));
        userLine = new QLineEdit(Login);
        userLine->setObjectName("userLine");
        userLine->setGeometry(QRect(100, 140, 289, 41));
        userLine->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 210);\n"
"border:none;\n"
"border-bottom:2px solid rgb(0,0,255);\n"
"color:rgb(0,0,0);\n"
"padding-bottom:7px;"));
        PassLine = new QLineEdit(Login);
        PassLine->setObjectName("PassLine");
        PassLine->setGeometry(QRect(100, 200, 289, 41));
        PassLine->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 210);\n"
"border:none;\n"
"border-bottom:2px solid rgb(0,0,255);\n"
"color:rgb(0,0,0);\n"
"padding-bottom:7px;"));
        PassLine->setEchoMode(QLineEdit::Password);
        LogButt = new QPushButton(Login);
        LogButt->setObjectName("LogButt");
        LogButt->setGeometry(QRect(200, 300, 83, 29));

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Dialog", nullptr));
        label->setText(QString());
        userLine->setPlaceholderText(QCoreApplication::translate("Login", "Username", nullptr));
        PassLine->setPlaceholderText(QCoreApplication::translate("Login", "Password", nullptr));
        LogButt->setText(QCoreApplication::translate("Login", "Log In", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
