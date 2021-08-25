#ifndef PLANT_GROUNDATTACK_H
#define PLANT_GROUNDATTACK_H
#include "plant.h"




class Plant_GroundAttack : public Plant
{
public:
    enum{Type = UserType + 4} override;
    Plant_GroundAttack();
    QRectF boundingRect() const  override;
    void advance(int phase) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    int type() const override;
};

#endif // PLANT_GROUNDATTACK_H
