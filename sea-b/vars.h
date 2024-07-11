#ifndef VARS_H
#define VARS_H


#define WID 10 //CHANGE THESE TO VARIABLES LATER
#define LEN 10
#define SQUARE 30
#define ANIMEFRAMES 20
#define NUM_SHIPS 10 // تعداد کشتی‌ها
#define SHIP_SIZE_1 4 // اندازه کشتی 1
#define SHIP_SIZE_2 3 // اندازه کشتی 2
#define SHIP_SIZE_3 2 // اندازه کشتی 3
#define SHIP_SIZE_4 1 // اندازه کشتی 4


enum gamephases
{
    //    duringanimation,
    //    gamebegin,
    placeships,
    playerturn,
    CPUturn,
    gameover
};

struct point
{
    short int shipis;
    bool hit;
};
typedef struct point MYPOINT;

struct cpupoint
{
    short int shipis;
    short int pointis;
};
typedef struct cpupoint CPU_POINT;

struct targetpoint
{
    short int x;
    short int y;
    CPU_POINT cpupnt;
};
typedef struct targetpoint TARGET_POINT;

enum direct
{
    NoD,
    Up,
    Right,
    Down,
    Left
};

enum cpu_point_is
{
    unknown,
    miss,
    hit,
    maybeship
};
#endif // VARS_H
