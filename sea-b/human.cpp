#include "human.h"

#include "gameships.h"
#include <QDebug>
#include "vars.h"

Human::Human()
{
    isCPU = false;

}

Human::~Human()
{

}


TARGET_POINT Human::Turn(int n, int m, MYPOINT* OPGrid[WID][LEN])
{
    return Human_Turn(n,m,OPGrid);
}

TARGET_POINT Human::Human_Turn(int n, int m, MYPOINT*OPGrid[WID][LEN])
{
    TARGET_POINT ret;

    ret.x = n;
    ret.y = m;

    OPGrid[n][m]->hit = true;
    if (OPGrid[n][m]->shipis > 0)
    {
        ret.cpupnt.shipis = OPGrid[n][m]->shipis;
        ret.cpupnt.pointis = hit;
    }
    else
    {
        ret.cpupnt.shipis = 0;
        ret.cpupnt.pointis = miss;
    }

    return ret;
}

bool Human::allShipsArePlaced()
{
    if(displayships::allocated[0] == true &&
        displayships::allocated[1] == true &&
        displayships::allocated[2] == true &&
        displayships::allocated[3] == true &&
        displayships::allocated[4] == true &&
        displayships::allocated[5] == true &&
        displayships::allocated[6] == true &&
        displayships::allocated[7] == true &&
        displayships::allocated[8] == true &&
        displayships::allocated[9] == true)
    {
        QRectF* d_ship[10];

        // Determine the bounding rectangles of each ship
        if(displayships::orientations[0] == 0) {
            d_ship[0] = new QRectF(displayships::x_pos[0], displayships::y_pos[0], SQUARE, SQUARE*1);
        } else {
            d_ship[0] = new QRectF(displayships::x_pos[0] - SQUARE*2, displayships::y_pos[0], SQUARE*1, SQUARE);
        }

        if(displayships::orientations[1] == 0) {
            d_ship[1] = new QRectF(displayships::x_pos[1], displayships::y_pos[1], SQUARE, SQUARE*1);
        } else {
            d_ship[1] = new QRectF(displayships::x_pos[1] - SQUARE*3, displayships::y_pos[1], SQUARE*1, SQUARE);
        }

        if(displayships::orientations[2] == 0) {
            d_ship[2] = new QRectF(displayships::x_pos[2], displayships::y_pos[2], SQUARE, SQUARE*1);
        } else {
            d_ship[2] = new QRectF(displayships::x_pos[2] - SQUARE*4, displayships::y_pos[2], SQUARE*1, SQUARE);
        }

        if(displayships::orientations[3] == 0) {
            d_ship[3] = new QRectF(displayships::x_pos[3], displayships::y_pos[3], SQUARE, SQUARE*1);
        } else {
            d_ship[3] = new QRectF(displayships::x_pos[3] - SQUARE*5, displayships::y_pos[3], SQUARE*1, SQUARE);
        }

        if(displayships::orientations[4] == 0) {
            d_ship[4] = new QRectF(displayships::x_pos[4], displayships::y_pos[4], SQUARE, SQUARE*2);
        } else {
            d_ship[4] = new QRectF(displayships::x_pos[4] - SQUARE*6, displayships::y_pos[4], SQUARE*2, SQUARE);
        }

        if(displayships::orientations[5] == 0) {
            d_ship[5] = new QRectF(displayships::x_pos[5], displayships::y_pos[5], SQUARE, SQUARE*2);
        } else {
            d_ship[5] = new QRectF(displayships::x_pos[5] - SQUARE*7, displayships::y_pos[5], SQUARE*2, SQUARE);
        }

        if(displayships::orientations[6] == 0) {
            d_ship[6] = new QRectF(displayships::x_pos[6], displayships::y_pos[6], SQUARE, SQUARE*2);
        } else {
            d_ship[6] = new QRectF(displayships::x_pos[6] - SQUARE*8, displayships::y_pos[6], SQUARE*2, SQUARE);
        }

        if(displayships::orientations[7] == 0) {
            d_ship[7] = new QRectF(displayships::x_pos[7], displayships::y_pos[7], SQUARE, SQUARE*3);
        } else {
            d_ship[7] = new QRectF(displayships::x_pos[7] - SQUARE*9, displayships::y_pos[7], SQUARE*3, SQUARE);
        }

        if(displayships::orientations[8] == 0) {
            d_ship[8] = new QRectF(displayships::x_pos[8], displayships::y_pos[8], SQUARE, SQUARE*3);
        } else {
            d_ship[8] = new QRectF(displayships::x_pos[8] - SQUARE*10, displayships::y_pos[8], SQUARE*3, SQUARE);
        }

        if(displayships::orientations[9] == 0) {
            d_ship[9] = new QRectF(displayships::x_pos[9], displayships::y_pos[9], SQUARE, SQUARE*4);
        } else {
            d_ship[9] = new QRectF(displayships::x_pos[9] - SQUARE*11, displayships::y_pos[9], SQUARE*4, SQUARE);
        }

        // Check for intersections or containment between ships
        for(int first = 1; first < 10; ++first) {
            for(int second = 0; second < first; ++second) {
                if(d_ship[first]->intersects(*d_ship[second]) || d_ship[first]->contains(*d_ship[second])) {
                    delete d_ship[0];
                    delete d_ship[1];
                    delete d_ship[2];
                    delete d_ship[3];
                    delete d_ship[4];
                    delete d_ship[5];
                    delete d_ship[6];
                    delete d_ship[7];
                    delete d_ship[8];
                    delete d_ship[9];
                    return false;
                }
            }
        }

        delete d_ship[0];
        delete d_ship[1];
        delete d_ship[2];
        delete d_ship[3];
        delete d_ship[4];
        delete d_ship[5];
        delete d_ship[6];
        delete d_ship[7];
        delete d_ship[8];
        delete d_ship[9];

        return true;
    }

    return false;
}
