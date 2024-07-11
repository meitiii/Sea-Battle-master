#include "signup.h"
#include "ui_signup.h"

#include <QRegularExpression>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QMessageBox>
#include <QCryptographicHash>
SignUp::SignUp(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SignUp)
{
    ui->setupUi(this);
}

SignUp::~SignUp()
{
    delete ui;
}

bool SignUp::isUsernameTaken(const QString &username) {
    QFile file("users.json");
    if (!file.open(QIODevice::ReadOnly)) {
        return false;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonArray users = doc.array();

    for (const QJsonValue &value : users) {
        QJsonObject user = value.toObject();
        if (user["username"].toString() == username) {
            return true;
        }
    }

    return false;
}

void SignUp::saveUserData(const QJsonObject &userData) {
    QFile file("users.json");
    QJsonArray users;

    if (file.exists()) {
        if (!file.open(QIODevice::ReadOnly)) {
            return;
        }

        QByteArray data = file.readAll();
        file.close();

        QJsonDocument doc = QJsonDocument::fromJson(data);
        users = doc.array();
    }

    users.append(userData);

    if (!file.open(QIODevice::WriteOnly)) {
        return;
    }

    QJsonDocument doc(users);
    file.write(doc.toJson());
    file.close();
}

bool SignUp::validateInput(const QString &firstName, const QString &lastName, const QString &username, const QString &password, const QString &email) {
    QRegularExpression nameRegExp("^[A-Za-z]+$");
    if (!nameRegExp.match(firstName).hasMatch()) {
        return false;
    }

    QRegularExpression lastNameRegExp("^[A-Za-z]+(-[A-Za-z]+)?$");
    if (!lastNameRegExp.match(lastName).hasMatch()) {
        return false;
    }

    QRegularExpression usernameRegExp("^[A-Za-z]([A-Za-z0-9._]*[A-Za-z0-9])?$");
    if (!usernameRegExp.match(username).hasMatch()) {
        return false;
    }
    if (username.contains("..") || username.contains("__") || username.contains("._") || username.contains("_.")) {
        return false;
    }

    if (password.length() < 6 || password.length() > 20) {
        return false;
    }
    QRegularExpression passwordRegExp("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[!@#$%^&*()\\-+=]).{6,20}$");
    if (!passwordRegExp.match(password).hasMatch()) {
        return false;
    }

    QStringList usernameParts = username.split(QRegularExpression("[._\\d]"), Qt::SkipEmptyParts);
    for (const QString &part : usernameParts) {
        if (part.length() > 3 && password.contains(part)) {
            return false;
        }
    }

    QRegularExpression emailRegExp("^[A-Za-z]([A-Za-z0-9._]*[A-Za-z0-9])?@[A-Za-z]+(\\.[A-Za-z]+)*\\.com$");
    if (!emailRegExp.match(email).hasMatch()) {
        return false;
    }

    if (password.contains(QRegularExpression("(.)\\1\\1\\1"))) {
        return false;
    }

    return true;
}
void SignUp::on_signButt_clicked()
{
    QString firstName = ui->firstnameLine->text();
    QString lastName = ui->lastnameLine->text();
    QString username = ui->userLine->text();
    QString password = ui->passLine->text();
    QString email = ui->emailLine->text();

    if (username.isEmpty() || password.isEmpty() || firstName.isEmpty() || lastName.isEmpty()||email.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please fill in all fields.");
        return;
    }

    if (validateInput(firstName, lastName, username, password, email)) {
        if (!isUsernameTaken(username)) {
            QString hashedPassword = QString(QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex());
            QJsonObject userData;
            userData["firstName"] = firstName;
            userData["lastName"] = lastName;
            userData["username"] = username;
            userData["password"] = hashedPassword;
            userData["email"] = email;

            saveUserData(userData);

            QMessageBox::information(this, "Success", "User registered successfully.");
            this->close();
        } else {
            QMessageBox::warning(this, "Error", "Username is already taken.");
        }
    } else {
        QMessageBox::warning(this, "Error", "Invalid input.");
    }
}
