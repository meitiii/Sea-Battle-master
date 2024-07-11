#ifndef PLAYER_H
#define PLAYER_H

#include "vars.h"
#include "gameships.h"


class Player
{
public:
    Player();
    virtual ~Player();
    bool placeShip(short int thisship, int x, int y);
    void removeShip(short int thisship);
    TARGET_POINT fireAtPoint(MYPOINT* OPGrid[WID][LEN], gameships* OPShips[NUM_SHIPS]);

    virtual TARGET_POINT Turn(int, int, MYPOINT*[WID][LEN]){TARGET_POINT ret;return ret;}

    bool isCPU;
    MYPOINT* PlayerGrid[WID][LEN];
    gameships* PlayerShips[10];
    TARGET_POINT targetedPoint;
};


#endif // PLAYER_H
