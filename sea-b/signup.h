#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>
#include <QJsonObject>
namespace Ui {
class SignUp;
}

class SignUp : public QDialog
{
    Q_OBJECT

public:
    explicit SignUp(QWidget *parent = nullptr);
    ~SignUp();
    bool validateInput(const QString &firstName, const QString &lastName, const QString &username, const QString &password, const QString &email);
    bool isUsernameTaken(const QString &username);
    void saveUserData(const QJsonObject &userData);

private slots:
    void on_signButt_clicked();

private:
    Ui::SignUp *ui;
};

#endif // SIGNUP_H
