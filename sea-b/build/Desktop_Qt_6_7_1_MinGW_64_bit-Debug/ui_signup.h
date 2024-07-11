/********************************************************************************
** Form generated from reading UI file 'signup.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_H
#define UI_SIGNUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignUp
{
public:
    QLabel *label;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *mainLayout;
    QLineEdit *firstnameLine;
    QLineEdit *lastnameLine;
    QLineEdit *userLine;
    QLineEdit *passLine;
    QLineEdit *emailLine;
    QPushButton *signButt;

    void setupUi(QDialog *SignUp)
    {
        if (SignUp->objectName().isEmpty())
            SignUp->setObjectName("SignUp");
        SignUp->resize(500, 422);
        label = new QLabel(SignUp);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 481, 401));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/Pictures/BackGround/paper.png);\n"
"border-radius:30px;"));
        verticalLayoutWidget = new QWidget(SignUp);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(90, 60, 321, 251));
        mainLayout = new QVBoxLayout(verticalLayoutWidget);
        mainLayout->setObjectName("mainLayout");
        mainLayout->setContentsMargins(0, 0, 0, 0);
        firstnameLine = new QLineEdit(verticalLayoutWidget);
        firstnameLine->setObjectName("firstnameLine");
        firstnameLine->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 210);\n"
"border:none;\n"
"border-bottom:2px solid rgb(0,0,255);\n"
"color:rgb(0,0,0);\n"
"padding-bottom:7px;"));

        mainLayout->addWidget(firstnameLine);

        lastnameLine = new QLineEdit(verticalLayoutWidget);
        lastnameLine->setObjectName("lastnameLine");
        lastnameLine->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 210);\n"
"border:none;\n"
"border-bottom:2px solid rgb(0,0,255);\n"
"color:rgb(0,0,0);\n"
"padding-bottom:7px;"));

        mainLayout->addWidget(lastnameLine);

        userLine = new QLineEdit(verticalLayoutWidget);
        userLine->setObjectName("userLine");
        userLine->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 210);\n"
"border:none;\n"
"border-bottom:2px solid rgb(0,0,255);\n"
"color:rgb(0,0,0);\n"
"padding-bottom:7px;"));

        mainLayout->addWidget(userLine);

        passLine = new QLineEdit(verticalLayoutWidget);
        passLine->setObjectName("passLine");
        passLine->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 210);\n"
"border:none;\n"
"border-bottom:2px solid rgb(0,0,255);\n"
"color:rgb(0,0,0);\n"
"padding-bottom:7px;"));

        mainLayout->addWidget(passLine);

        emailLine = new QLineEdit(verticalLayoutWidget);
        emailLine->setObjectName("emailLine");
        emailLine->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 210);\n"
"border:none;\n"
"border-bottom:2px solid rgb(0,0,255);\n"
"color:rgb(0,0,0);\n"
"padding-bottom:7px;"));

        mainLayout->addWidget(emailLine);

        signButt = new QPushButton(SignUp);
        signButt->setObjectName("signButt");
        signButt->setGeometry(QRect(200, 330, 83, 29));

        retranslateUi(SignUp);

        QMetaObject::connectSlotsByName(SignUp);
    } // setupUi

    void retranslateUi(QDialog *SignUp)
    {
        SignUp->setWindowTitle(QCoreApplication::translate("SignUp", "Dialog", nullptr));
        label->setText(QString());
        firstnameLine->setText(QString());
        firstnameLine->setPlaceholderText(QCoreApplication::translate("SignUp", "First Name", nullptr));
        lastnameLine->setPlaceholderText(QCoreApplication::translate("SignUp", "Last Name", nullptr));
        userLine->setPlaceholderText(QCoreApplication::translate("SignUp", "Username", nullptr));
        passLine->setPlaceholderText(QCoreApplication::translate("SignUp", "Password", nullptr));
        emailLine->setPlaceholderText(QCoreApplication::translate("SignUp", "Email", nullptr));
        signButt->setText(QCoreApplication::translate("SignUp", "Sign Up", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignUp: public Ui_SignUp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H
