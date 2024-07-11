/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLabel *label;
    QPushButton *signupButtom;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(500, 425);
        label = new QLabel(Dialog);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 481, 411));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/Pictures/BackGround/PaperBackground.png);"));
        signupButtom = new QPushButton(Dialog);
        signupButtom->setObjectName("signupButtom");
        signupButtom->setGeometry(QRect(190, 160, 111, 29));
        signupButtom->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color:black;"));
        pushButton_2 = new QPushButton(Dialog);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(190, 200, 111, 29));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color:black;"));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        label->setText(QString());
        signupButtom->setText(QCoreApplication::translate("Dialog", "Sign Up", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Dialog", "Log In", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
