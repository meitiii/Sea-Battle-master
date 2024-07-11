#include "login.h"
#include "ui_login.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QMessageBox>
#include <QCryptographicHash>
Login::Login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_LogButt_clicked()
{
    QString username = ui->userLine->text();
    QString password = ui->PassLine->text();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please fill in all fields.");
        return;
    }

    // هش کردن پسورد
    QString hashedPassword = QString(QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex());

    QFile file("users.json");
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, "Error", "Failed to open JSON file.");
        return;
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
    if (jsonDoc.isNull() || !jsonDoc.isArray()) {
        QMessageBox::warning(this, "Error", "Invalid JSON file.");
        return;
    }

    QJsonArray usersArray = jsonDoc.array();
    for (const QJsonValue &userValue : usersArray) {
        QJsonObject userObject = userValue.toObject();
        if (userObject["username"].toString() == username && userObject["password"].toString() == hashedPassword) {
            log=true;
            QMessageBox::information(this, "Success", "Login successful.");
            this->close();
            return;
        }
    }

    QMessageBox::warning(this, "Error", "Invalid username or password.");
}
