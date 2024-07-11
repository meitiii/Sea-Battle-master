#include "selectship.h"

#include "displayships.h"
#include "vars.h"

selectship::selectship(QGraphicsScene *Mscene, int num)
{
    scene = Mscene;

    shipnum = num;

    shipsize = shipnum + 2;
    switch (shipnum) {
    case 1:
    case 2:
    case 3:
        shipsize = 2;
        break;
    case 4:
    case 5:
    case 6:
        shipsize = 3;
        break;
    case 7:
    case 8:
    case 9:
    case 10:

        shipsize = 4;
        break;
    default:
        shipsize = 2; // برای هر شماره کشتی که از 1 تا 10 نباشد، به صورت پیش‌فرض اندازه 2 را تعیین کنید.
        break;
    }
    Show = true;
    Sunk = false;

    orient = 0;
    //setFlag(ItemIsMovable);
    // DrawShip();
}

QRectF selectship::boundingRect() const
{
    switch(shipsize)
    {
    case 2:
        return QRectF(0,0,30,20);
        break;
    case 3:
        return QRectF(0,30,50,20);
        break;
    case 4:
        return QRectF(0,60,70,20);
        break;
    case 5:
        return QRectF(0,90,90,20);
        break;
    }
    return QRectF(0,0,0,0);
}


void selectship::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QRectF rec = boundingRect();
    QBrush brush(Qt::blue);

    if(Show)
    {
        brush.setColor(Qt::green);
    }
    else
    {
        brush.setColor(Qt::white);
    }

    if (Sunk ==true)
    {
        brush.setColor(Qt::red);
    }


    painter->fillRect(rec,brush);
    painter->drawRect(rec);
}


//void selectship::DrawShip()
//{

    // rectangle[n][m] = scene->addRect(x, y, offset, offset, *blackpen, *definedBrush);
    // scene->addRect(SQUARE, SQUARE, SQUARE, 120, *blackpen, *redBrush);
    //ship->boundingRect(SQUARE, 120);
    // setFlag(QGraphicsItem::ItemIsMovable);
//}


void selectship::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *)
{
    emit Clicked(shipnum);

    if(displayships::phaseIsSetupShips)
        delete this;
}


void selectship::OnSunk(int shipvalue)
{
    if(shipvalue == shipnum)
    {
        Sunk = true;
    }
    update();
}

