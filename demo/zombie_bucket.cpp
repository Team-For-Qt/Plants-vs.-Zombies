#include "zombie_bucket.h"

Zombie_Bucket::Zombie_Bucket()
{
    condition = 1;
    bv = 600;
    ht = 50;
    speed  = 3;
    setMovie(":/image/images/Zombie_Iron_Walk.gif");
}

void Zombie_Bucket::advance(int phase)
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
            if(condition == 1 )
            {
                setMovie(":/image/images/Zombie_Iron_Hurt.gif");
                condition = 2;
            }
            Plant *plant = qgraphicsitem_cast<Plant *>(items[0]);
            plant->bv -= ht;
            return;
        }
        else {
            if(condition == 2){
                condition = 1;
                setMovie(":/image/images/Zombie_Iron_Walk.gif");
            }
        }
    }
    setX(x()-speed);
}
