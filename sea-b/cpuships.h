#ifndef CPUSHIPS_H
#define CPUSHIPS_H

#include <QObject>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsItem>

#include "vars.h"
#define SHIP1SIZE 2
#define SHIP2SIZE 3
#define SHIP3SIZE 3
#define SHIP4SIZE 4
#define SHIP5SIZE 5
#define SHIP6SIZE 2
#define SHIP7SIZE 3
#define SHIP8SIZE 3
#define SHIP9SIZE 4
#define SHIP10SIZE 5

class cpuships : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit cpuships(QGraphicsScene *Mscene, int num);

    int shipsize;
    int shipnum;

    void DrawShip();
    void ReOrientShip();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);

    int orient;
    bool Show;

    QGraphicsScene *scene;
    QGraphicsRectItem *ship;

    QBrush *redBrush;
    QBrush *blueBrush;
    QBrush *grayBrush;
    QBrush *definedBrush;
    QPen *blackpen;

private slots:
    void OnSunk(int shipnumber);

signals:
    void SunkTest(int n);

};
#endif // CPUSHIPS_H
