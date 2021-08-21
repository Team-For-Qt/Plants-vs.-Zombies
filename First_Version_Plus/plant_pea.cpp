#include "plant_pea.h"
#include "zombie.h"
#include "weapon.h"
#include "weapon_pea.h"
#include<QDebug>
#include "zombie_basic.h"

Plant_Pea::Plant_Pea()
{
    setMovie(":/image/images/Peashooter.gif");
    time=10;
    bv=200;
    cnt=0;
}
void Plant_Pea::advance(int phase){
    if(!phase)
        return;
    update();
    if(bv<=0)
        delete this;
    if(++cnt>time){
        cnt=0;
        if(!collidingItems().isEmpty()){
           Weapon *w = new Weapon_Pea;
           w->setPos(x()+30,y());
           scene()->addItem(w);
           return;
        }
    }
}

bool Plant_Pea::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)
    return other->type() == Zombie::Type && qFuzzyCompare(other->y(), y());
}

