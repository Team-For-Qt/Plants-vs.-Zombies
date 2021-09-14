#ifndef PLANT_CHOMPER_H
#define PLANT_CHOMPER_H
#include "plant.h"
#include "zombie.h"

class Plant_Chomper : public Plant
{
public:
    Plant_Chomper();
    int condition;
    /*
     * ‘0’代表死亡
     * ‘1’代表普通状态
     * ‘2’代表攻击
     * ‘3’代表消化
     */
    void advance(int phase)override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    QRectF boundingRect() const override;
};

#endif // PLANT_CHOMPER_H
