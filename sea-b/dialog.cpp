#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
    ,sign_up(new SignUp(this))
    ,log_in(new Login(this))
{
    ui->setupUi(this);
    QMediaPlayer* player = new QMediaPlayer;
    QAudioOutput* audioOutput = new QAudioOutput;
    player->setAudioOutput(audioOutput);
    player->setSource(QUrl::fromLocalFile("C:\\Users\\user\\Desktop\\BattleshipGame\\BattleshipGame\\music\\Ocean.mp3"));
    audioOutput->setVolume(0.5);
    player->setLoops(QMediaPlayer::Infinite);
    player->play();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_signupButtom_clicked()
{
    sign_up->show();

}


void Dialog::on_pushButton_2_clicked()
{
    log_in->exec();
    if(log_in->log==true){
        //player->stop();
        this->close();
    }
}
