#include "zombie_jump.h"

Zombie_Jump::Zombie_Jump()
{
    condition = 1;
        bv = 500;
        ht = 20;
        speed  = 3;
        setMovie(":/image/images/Zombie_Jump_Walk1.gif");
}

/*
 * ‘0’代表死亡
 * ‘1’代表有杆行走
 * ‘2’代表伤害植物
 * ‘3’代表冰冻
 * ‘10’代表跳
 * ‘11’代表无杆行走
 */

void Zombie_Jump::advance(int phase)
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
    QList<QGraphicsItem *> items = collidingItems();
    if(!items.isEmpty()){
        if(condition == 1)
        {
            condition = 10;
            setX(x() - 10);
            setMovie(":/image/images/Zombie_Jump_Jump.gif");
        }
        if(condition == 11)
        {
            condition = 2;
            setMovie(":/image/images/Zombie_Jump_Eat.gif");

        }
         if(condition == 2)
         {
             Plant *plant = qgraphicsitem_cast<Plant *>(items[0]);
             plant->bv -= ht;
         }
        return;
    }
    else {
        if(condition == 2 || (condition == 10 && movie->currentFrameNumber() == movie->frameCount() - 1)){
            condition = 11;
            setMovie(":/image/images/Zombie_Jump_Walk2.gif");
            return ;
        }
    }


    setX(x()-speed);
}

//bool Zombie_Jump::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
//{
//    return
//}

