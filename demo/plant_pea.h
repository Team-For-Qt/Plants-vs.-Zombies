#ifndef PLANT_PEA_H
#define PLANT_PEA_H

#include<QMovie>
#include "plant.h"
#include "zombie.h"
#include "weapon.h"
#include "weapon_pea.h"


class Plant_Pea : public Plant
{
public:
    Plant_Pea();
    void advance(int phase)override;    
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
};

#endif // PLANT_PEA_H
