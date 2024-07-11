#include "mainwindow.h"
#include "displayships.h"
#include "dialog.h"
#include <QApplication>
#include <QTime>

bool displayships::phaseIsSetupShips = true;
bool displayships::allocated[] = {false,false,false,false,false,false,false,false,false,false};
bool displayships::orientations[] = {0,0,0,0,0,0,0,0,0,0};
int displayships::x_pos[] = {0,0,0,0,0,0,0,0,0,0};
int displayships::y_pos[] = {0,0,0,0,0,0,0,0,0,0};


int main(int argc, char *argv[])
{
    QTime time = QTime::currentTime();
    srand((uint)time.msec());

    QApplication a(argc, argv);
    Dialog d;
    d.exec();
    MainWindow w;
    w.show();

    return a.exec();
}
