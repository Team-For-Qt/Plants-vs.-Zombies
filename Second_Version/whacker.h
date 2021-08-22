#ifndef WHACKER_H
#define WHACKER_H
#include "messy.h"

class Whacker : public Messy
{
public:
    Whacker();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)override;

};

#endif // WHACKER_H
