#ifndef DIALOG_H
#define DIALOG_H

#include "signup.h"
#include "login.h"
#include <QDialog>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QUrl>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:

    void on_signupButtom_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Dialog *ui;
    SignUp* sign_up;
    Login* log_in;
    QMediaPlayer *player;
    QAudioOutput* audioOutput;
};
#endif // DIALOG_H
