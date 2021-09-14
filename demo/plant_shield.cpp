#include "plant_shield.h"
#include "zombie.h"

Plant_shield::Plant_shield()
{
    condition = 1;
    cnt = 0;
    time = 300;
    bv = 6000;
    setMovie(":/image/images/shield.gif");
}


void Plant_shield::advance(int phase)
{
    if(!phase)return;
    update();
    if(bv <= 0) delete this;
    else
    {
        if(bv > 4000 && condition == 1)
        {
            condition = 2;
            return ;
        }
        if(bv > 2000 && bv < 4000 && condition == 2){
            condition = 3;
            setMovie(":/image/images/shield0.gif");
            return ;
        }
        if(bv > 0 && bv < 2000 && condition == 3)
        {
            condition =0;
            setMovie(":/image/images/shield1.gif");
            return ;
        }
    }

}


bool Plant_shield::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode);
    return other->type() == Zombie::Type && qFuzzyCompare(y(),other->y()) && qAbs(x() - other->x()) < 15;
}


