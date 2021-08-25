#ifndef BOX_GROUNATTACK_H
#define BOX_GROUNATTACK_H

#include "box.h"


class Box_GrounAttack : public Box
{
public:
    Box_GrounAttack();
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

};

#endif // BOX_GROUNATTACK_H
