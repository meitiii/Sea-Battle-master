#include <QMainWindow>
#include <QGraphicsView>
#include "mainwindow.h"
#include "vars.h"
#include "displayships.h"
#include "selectship.h"
#include "battleshipgame.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "blast.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton_2->setEnabled(false);

    ui->pushButton->hide();
    ui->pushButton_3->hide();
    ui->pushButton_4->hide();
    ui->pushButton_5->hide();
    ui->pushButton_6->hide();

    bsg = new BattleshipGame();
    connect(bsg, SIGNAL(setPhaseText(QString)), this, SLOT(onPhaseTextSet(QString)));
    connect(bsg, SIGNAL(humanAnimationDone(int, int, int)), this, SLOT(whenHumanAnimationDone(int, int, int)));

    ui->graphicsView->setSceneRect(0,0,WID*SQUARE,LEN*SQUARE);
    ui->graphicsView_2->setSceneRect(0,0,WID*SQUARE,LEN*SQUARE);
    ui->graphicsView_3->setSceneRect(0, 0, WID * SQUARE, LEN * SQUARE);
    thiscolor = new QColor(Qt::gray);//new QColor(127, 127, 127);

    bsg->scene = new QGraphicsScene(this);
    bsg->scene2 = new QGraphicsScene(this);
    bsg->scene3 = new QGraphicsScene(this);
    ui->graphicsView->setScene(bsg->scene);
    ui->graphicsView_2->setScene(bsg->scene2);
    ui->graphicsView_3->setScene(bsg->scene3);

    redBrush = new QBrush(Qt::red);
    blueBrush = new QBrush(Qt::blue);
    grayBrush = new QBrush(Qt::lightGray);


    definedBrush = new QBrush(*thiscolor);


    blackpen = new QPen(Qt::black);
    blackpen->setWidth(1);

    timesup = new QTimer(this);
    connect(timesup, SIGNAL(timeout()), bsg,SLOT(advance()));
    timesup->start(500/ANIMEFRAMES);


    DrawLayout();


    for (int i = 0; i < 10; ++i) {
        bsg->humanplayer->selship[i] = new selectship(bsg->scene3, 9-i);
        bsg->scene3->addItem(bsg->humanplayer->selship[i]);
        connect(bsg->humanplayer->selship[i], SIGNAL(Clicked(int)), this, SLOT(OnClick(int)));
    }


    for (int i = 0; i < 10; ++i) {
        bsg->cpuship[i] = new cpuships(bsg->scene3, 9-i);
        bsg->scene3->addItem(bsg->cpuship[i]);
        connect(bsg, SIGNAL(sinkCPUShip(int)), bsg->cpuship[i], SLOT(OnSunk(int)));
    }

}

MainWindow::~MainWindow()
{

}

void MainWindow::DrawLayout()
{
    int n;
    int m;
    ui->graphicsView->centerOn(QPointF(WID*SQUARE/2,LEN*SQUARE/2));

    int x;
    int y;

    int offset = SQUARE;

    for (n = 0, x = 0; n < WID; ++n, x += offset)
    {
        for (m = 0, y = 0; m < LEN; ++m, y += offset)
        {
            bsg->HumanSquares[n][m] = bsg->scene->addRect(x, y, offset, offset, *blackpen, *definedBrush);
            bsg->CPUsquares[n][m] = new boardsquare(bsg->scene2, offset, x, y, n, m);

            connect(bsg->CPUsquares[n][m], SIGNAL(Clicked(int, int)), this, SLOT(OnReceiveNM(int,int)));
            connect(this, SIGNAL(SendDothis(int,int,int)), bsg->CPUsquares[n][m], SLOT(OnReceiveOrders(int,int,int)));
        }
    }
}

void MainWindow::NewGame()
{
    delete bsg->cpuplayer;
    bsg->blastanimation->blastframe = 0;
    bsg->animeframes = 0;
    for (int x = 0; x < WID; ++x)
    {
        for (int y = 0; y < LEN; ++y)
        {
            delete bsg->HumanSquares[x][y];
            delete bsg->CPUsquares[x][y];
        }
    }
    for(;bsg->NumberOfHumanGridPointsShot > 0;)
    {
        delete bsg->HumanGridPointsShot[--bsg->NumberOfHumanGridPointsShot];
    }
    if(bsg->gamephase != placeships)
    {
        for(int z = 0; z < 10; ++z)
        {
            delete bsg->cpuship[z];
        }
    }
    for(int z = 0; z < 10; ++z)
    {
        delete bsg->humanplayer->ship[z];
        delete bsg->humanplayer->selship[z];
    }
    for(int x=0;x<WID;++x)
    {
        for(int y=0;y<WID;++y)
        {
            delete bsg->humanplayer->PlayerGrid[x][y];
        }
    }
    for(int bazinga=0;bazinga<10;++bazinga)
    {
        delete bsg->humanplayer->PlayerShips[bazinga];
    }
    bsg->gamephase = placeships;



    ui->pushButton_2->setEnabled(false);
    ui->pushButton_2->setText("Begin Game");
    ui->phaselabel->setText("Place Ships");
    bsg->cpuplayer = new CPU();

    DrawLayout();
    for (int i = 0; i < 10; ++i) {
        bsg->humanplayer->selship[i] = new selectship(bsg->scene3, 9-i);
        bsg->scene3->addItem(bsg->humanplayer->selship[i]);
        connect(bsg->humanplayer->selship[i], SIGNAL(Clicked(int)), this, SLOT(OnClick(int)));
    }

    for (int i = 0; i < 10; ++i) {
        bsg->cpuship[i] = new cpuships(bsg->scene3, 9-i);
        bsg->scene3->addItem(bsg->cpuship[i]);
        connect(bsg, SIGNAL(sinkCPUShip(int)), bsg->cpuship[i], SLOT(OnSunk(int)));
    }

    for(int x=0;x<WID;++x)
    {
        for(int y=0;y<WID;++y)
        {
            bsg->humanplayer->PlayerGrid[x][y] = new MYPOINT;
            bsg->humanplayer->PlayerGrid[x][y]->hit = false;
            bsg->humanplayer->PlayerGrid[x][y]->shipis = 0;
        }
    }
    for(int bazinga=0;bazinga<10;++bazinga)
    {
        bsg->humanplayer->PlayerShips[bazinga] = new gameships(bazinga+1);
    }
    bsg->humanplayer->targetedPoint.cpupnt.pointis = -1;
    bsg->humanplayer->targetedPoint.cpupnt.shipis = -1;
    bsg->humanplayer->targetedPoint.x = -1;
    bsg->humanplayer->targetedPoint.y = -1;

    displayships::phaseIsSetupShips = true;
    for(int bazinga=0;bazinga<10;++bazinga)
    {
        displayships::allocated[bazinga] = false;
        displayships::orientations[bazinga] = 0;
        displayships::x_pos[bazinga] = 0;
        displayships::y_pos[bazinga] = 0;
    }
}

void MainWindow::OnClick(int shipnum)
{
    bsg->humanplayer->ship[shipnum] = new displayships(bsg->scene, shipnum);
    bsg->scene->addItem(bsg->humanplayer->ship[shipnum]);
    displayships::allocated[shipnum] = true;
    connect(bsg->humanplayer->ship[shipnum], SIGNAL(displayship_clicked(int)), this, SLOT(OnDisplayshipClicked(int)));
    OnDisplayshipClicked(shipnum);

    return;
}
void MainWindow::OnDisplayshipClicked(int)
{
    if(bsg->allHumanShipsArePlaced())
    {
        ui->pushButton_2->setEnabled(true);
    }
    else
    {
        ui->pushButton_2->setEnabled(false);
    }
}

void MainWindow::OnReceiveNM(int n, int m)
{

    if(bsg->gamephase==playerturn && bsg->animeframes == 0)
    {
        bsg->humanplayer->targetedPoint.x = n;
        bsg->humanplayer->targetedPoint.y = m;
        bsg->humanplayer->fireAtPoint(bsg->cpuplayer->PlayerGrid,bsg->cpuplayer->PlayerShips);

        onPhaseTextSet("You fire!");
        bsg->blastanimation->blastframe = 0;
        bsg->blastanimation->setPos(n*SQUARE+(SQUARE/2),m*SQUARE+(SQUARE/2));
        bsg->scene2->addItem(bsg->blastanimation);
        bsg->animeframes = ANIMEFRAMES;
    }
}
void MainWindow::whenHumanAnimationDone(int n, int m, int doThis)
{
    emit SendDothis(n, m, doThis);
}

void MainWindow::onPhaseTextSet(QString newtext)
{
    ui->phaselabel->setText(newtext);
}

void MainWindow::on_pushButton_2_clicked()
{
    if(bsg->gamephase == placeships)
    {
        displayships::phaseIsSetupShips = false;

        for(short int ship = 0; ship < 10; ++ship)
        {
            if(displayships::orientations[ship] == 0)
            {
                bsg->humanplayer->PlayerShips[ship]->direction = Down;
                bsg->humanplayer->placeShip(ship+1,displayships::x_pos[ship]/SQUARE,displayships::y_pos[ship]/SQUARE);
            }
            else
            {
                bsg->humanplayer->PlayerShips[ship]->direction = Left;
                bsg->humanplayer->placeShip(ship+1,(displayships::x_pos[ship]/SQUARE)-(bsg->humanplayer->PlayerShips[ship]->size),displayships::y_pos[ship]/SQUARE);
            }


        }
        bsg->cpuplayer->setUpCPUShips();

        bsg->humanplayer->selship[0] = new selectship(bsg->scene3, 9);
        bsg->scene3->addItem(bsg->humanplayer->selship[0]);
        connect(bsg, SIGNAL(sinkPlayerShip(int)), bsg->humanplayer->selship[0], SLOT(OnSunk(int)));

        bsg->humanplayer->selship[1] = new selectship(bsg->scene3, 8);
        bsg->scene3->addItem(bsg->humanplayer->selship[1]);
        connect(bsg, SIGNAL(sinkPlayerShip(int)), bsg->humanplayer->selship[1], SLOT(OnSunk(int)));

        bsg->humanplayer->selship[2] = new selectship(bsg->scene3, 7);
        bsg->scene3->addItem(bsg->humanplayer->selship[2]);
        connect(bsg, SIGNAL(sinkPlayerShip(int)), bsg->humanplayer->selship[2], SLOT(OnSunk(int)));

        bsg->humanplayer->selship[3] = new selectship(bsg->scene3, 6);
        bsg->scene3->addItem(bsg->humanplayer->selship[3]);
        connect(bsg, SIGNAL(sinkPlayerShip(int)), bsg->humanplayer->selship[3], SLOT(OnSunk(int)));

        bsg->humanplayer->selship[4] = new selectship(bsg->scene3, 5);
        bsg->scene3->addItem(bsg->humanplayer->selship[4]);
        connect(bsg, SIGNAL(sinkPlayerShip(int)), bsg->humanplayer->selship[4], SLOT(OnSunk(int)));

        bsg->humanplayer->selship[5] = new selectship(bsg->scene3, 4);
        bsg->scene3->addItem(bsg->humanplayer->selship[5]);
        connect(bsg, SIGNAL(sinkPlayerShip(int)), bsg->humanplayer->selship[5], SLOT(OnSunk(int)));

        bsg->humanplayer->selship[6] = new selectship(bsg->scene3, 3);
        bsg->scene3->addItem(bsg->humanplayer->selship[6]);
        connect(bsg, SIGNAL(sinkPlayerShip(int)), bsg->humanplayer->selship[6], SLOT(OnSunk(int)));

        bsg->humanplayer->selship[7] = new selectship(bsg->scene3, 2);
        bsg->scene3->addItem(bsg->humanplayer->selship[7]);
        connect(bsg, SIGNAL(sinkPlayerShip(int)), bsg->humanplayer->selship[7], SLOT(OnSunk(int)));

        bsg->humanplayer->selship[8] = new selectship(bsg->scene3, 1);
        bsg->scene3->addItem(bsg->humanplayer->selship[0]);
        connect(bsg, SIGNAL(sinkPlayerShip(int)), bsg->humanplayer->selship[0], SLOT(OnSunk(int)));

        bsg->humanplayer->selship[9] = new selectship(bsg->scene3, 0);
        bsg->scene3->addItem(bsg->humanplayer->selship[9]);
        connect(bsg, SIGNAL(sinkPlayerShip(int)), bsg->humanplayer->selship[9], SLOT(OnSunk(int)));



        switch(randomnum(2))
        {
        case 0:
            bsg->changetoPlayerTurn();
            break;
        case 1:
            bsg->changetoCPUTurn();
            break;
        default:
            qDebug() << "OUR LOGIC IS ABYSMAL";
            break;
        }

        ui->pushButton_2->setText("New Game");


    }
    else
    {
        NewGame();
    }
}
