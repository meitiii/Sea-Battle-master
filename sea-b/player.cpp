#include "player.h"

#include "gameships.h"


Player::Player()
{

    for (int i = 0; i < NUM_SHIPS; ++i) {
        switch (i + 1) {
        case 1:
        case 2:
        case 3:
            PlayerShips[i] = new gameships(1);
            break;
        case 4:
        case 5:
        case 6:
            PlayerShips[i] = new gameships(2);
            break;
        case 7:
        case 8:
        case 9:
            // break;
            PlayerShips[i] = new gameships(3);
            break;
        case 10:
            PlayerShips[i] = new gameships(4);
            break;
        default:
            break;
        }
    }
    for (int x = 0; x < WID; ++x) {
        for (int y = 0; y < LEN; ++y) {
            PlayerGrid[x][y] = new MYPOINT();
        }
    }

}

Player::~Player()
{
    for(int x=0;x<WID;++x)
    {
        for(int y=0;y<WID;++y)
        {
            delete PlayerGrid[x][y];
        }
    }
    for(int bazinga=0;bazinga<10;++bazinga)
    {
        delete PlayerShips[bazinga];
    }
}

bool Player::placeShip(short int thisship, int x, int y)//x and y are grid coords
{
    QPoint theSquare;
    theSquare.setX(x);
    theSquare.setY(y);

    if(PlayerShips[thisship-1]->placeThisShip(PlayerGrid,theSquare))
    {
        return true;
    }
    return false;
}
void Player::removeShip(short int thisship)
{
    if(thisship > 0 && PlayerShips[thisship-1]->placed == true)
    {
        PlayerShips[thisship-1]->removeThisShip(PlayerGrid);
    }
}

TARGET_POINT Player::fireAtPoint(MYPOINT* OPGrid[WID][LEN], gameships* OPShips[NUM_SHIPS])
{
    TARGET_POINT doubtingPoint;
    if(isCPU)
    {
        targetedPoint = Turn(0,0,OPGrid);
        targetedPoint.cpupnt.shipis = OPGrid[targetedPoint.x][targetedPoint.y]->shipis;

        if(targetedPoint.cpupnt.shipis > 0)
        {
            OPShips[targetedPoint.cpupnt.shipis-1]->getHitAt(targetedPoint.x,targetedPoint.y);
        }
        return targetedPoint;
    }
    else
    {
        doubtingPoint = Turn(targetedPoint.x,targetedPoint.y,OPGrid);
        if(doubtingPoint.cpupnt.pointis == -1)
        {
            return doubtingPoint;
        }
        targetedPoint = doubtingPoint;
        if(targetedPoint.cpupnt.shipis > 0)
        {
            OPShips[targetedPoint.cpupnt.shipis-1]->getHitAt(targetedPoint.x,targetedPoint.y);
        }
        return targetedPoint;
    }
}
