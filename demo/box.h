#ifndef BOX_H
#define BOX_H
#include "messy.h"
#include <QPainter>
#include <QDrag>

class Box : public Messy
{
public:
    int counter;
    Box();
    QString name;
    int cost;
    int cool;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void advance(int phase) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // BOX_H
