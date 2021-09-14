#ifndef PLANT_PEASNOW_H
#define PLANT_PEASNOW_H
#include "plant.h"
#include "zombie.h"
#include "weapon.h"
#include "weapon_peasnow.h"


class Plant_PeaSnow : public Plant
{
public:
    Plant_PeaSnow();
    void advance(int phase)override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
};

#endif // PLANT_PEASNOW_H
