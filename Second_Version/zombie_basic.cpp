#include "zombie_basic.h"

Zombie_Basic::Zombie_Basic()
{
    condition = 1;
    bv = 100;
    ht = 80;
    speed = 5;
    if (qrand() % 2)
        setMovie(":/image/images/ZombieWalk1.gif");
    else
        setMovie(":/image/images/ZombieWalk2.gif");
}

void Zombie_Basic::advance(int phase)
{
    if(!phase)return;
    update();
    if(bv<=0){
        if(condition)
        {
            condition = 0;
            setMovie(":/image/images/Zombie_new.gif");
        }
        else if (movie->currentFrameNumber() == movie->frameCount() - 1)
            delete this;
        return;
    }
    else{
        QList<QGraphicsItem *> items = collidingItems();
        if(!items.isEmpty()){
            if(condition == 1)
            {
                setMovie(":/image/images/Zombie_Hurt.gif");
                condition = 2;
            }
            Plant *plant = qgraphicsitem_cast<Plant *>(items[0]);
            plant->bv -= ht;
            return;
        }
        else {
            if(condition == 2){
                condition = 1;
                if (qrand() % 2)
                    setMovie(":/image/images/ZombieWalk1.gif");
                else
                    setMovie(":/image/images/ZombieWalk2.gif");
            }
        }
    }
    setX(x()-speed);
}
