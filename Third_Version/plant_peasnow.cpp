#include "plant_peasnow.h"

Plant_PeaSnow::Plant_PeaSnow()
{
    setMovie(":/image/images/SnowShooter.gif");
    time=20;
    bv=200;
    cnt=0;
}

void Plant_PeaSnow::advance(int phase)
{
    if(!phase)
    return;
    update();
    if(bv<=0)
        delete this;
    if(++cnt>time){
        cnt=0;
        if(!collidingItems().isEmpty()){
           Weapon *w = new Weapon_PeaSnow;
           w->setPos(x()+30,y());
           scene()->addItem(w);
           return;
        }
    }
}

bool Plant_PeaSnow::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)
    return other->type() == Zombie::Type && qFuzzyCompare(other->y(), y());
}
