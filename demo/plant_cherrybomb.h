#ifndef PLANT_CHERRYBOMB_H
#define PLANT_CHERRYBOMB_H
#include "plant.h"
#include "zombie.h"


class Plant_CherryBomb : public Plant
{
public:
    Plant_CherryBomb();
    QRectF boundingRect() const override;
    void advance(int phase) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    int condition;
    /*
     *‘ 0 ’代表放上去
     *‘ 1 ’代表炸
     */

};

#endif // PLANT_CHERRYBOMB_H
