#ifndef PLANT_SHIELD_H
#define PLANT_SHIELD_H

#include "plant.h"

class Plant_shield : public Plant
{
public:
    Plant_shield();
    int condition;
    /*
     * ‘0’代表死亡
     * ‘1’代表正常
     * ‘2’代表被啃一次
     * ‘3’代表被啃两次
     */
    void advance(int phase)override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;

};

#endif // PLANT_SHIELD_H
