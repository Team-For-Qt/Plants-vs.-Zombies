#ifndef ENERGY_H
#define ENERGY_H
#include "messy.h"

class Energy : public Messy
{
public:
    Energy();
    Energy(QPointF pos);
    ~Energy() override;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void advance(int phase) override;
private:
    QMovie *movie;
    QPointF dtn;
    int cnt;
    int time;
    qreal speed;
};

#endif // ENERGY_H
