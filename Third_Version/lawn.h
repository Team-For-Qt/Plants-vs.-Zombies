#ifndef LAWN_H
#define LAWN_H
#include "messy.h"
#include "plant.h"
#include <QtWidgets>
#include <QGraphicsItem>
#include <QGraphicsSceneDragDropEvent>


class Lawn : public Messy
{
public:
    Lawn();

    int map[10][15];
    //const static QMap<QString, int> map;

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget ) override;

    void dragEnterEvent(QGraphicsSceneDragDropEvent *event) override;
    void dragLeaveEvent(QGraphicsSceneDragDropEvent *event) override;
    void dropEvent(QGraphicsSceneDragDropEvent *event) override;

    bool dragOver;
};

#endif // LAWN_H
