#ifndef SUN_NUM_H
#define SUN_NUM_H

#include "box.h"

#include <QGraphicsItem>
class Sun_Num : public Box
{
public:
    Sun_Num();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // SUN_NUM_H
