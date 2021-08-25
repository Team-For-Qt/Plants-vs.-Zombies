#include "plant_chomper.h"
#include <QDebug>

Plant_Chomper::Plant_Chomper()
{
    condition = 1;
    bv = 999999;
    cnt = 0;
    time = 250;
    ht = 800;
    setMovie(":/image/images/Plant_Chomper.gif");
}

void Plant_Chomper::advance(int phase)
{
    if(!phase)return;
    update();
    if(bv <= 0){
        delete this;
    }
    QList<QGraphicsItem *> items = collidingItems();
    if(condition == 1){
        if(!collidingItems().isEmpty()){
            condition = 2;
            setMovie(":/image/images/Plant_Chomper_Hurt.gif");
            return;
        }
    }
    if (movie->currentFrameNumber() == movie->frameCount() - 1 && condition == 2){
        Zombie *zombie = qgraphicsitem_cast<Zombie *>(items[qrand() % items.size()]);
        condition = 3;
        zombie->bv -= ht;
    }
    if(condition == 3){
        setMovie(":/image/images/Plant_Chomper_Eat.gif");
        condition = 4;
    }
    if(++cnt > time && condition == 4){
        condition = 1;
        setMovie(":/image/images/Plant_Chomper.gif");
        cnt = 0;
    }
}


bool Plant_Chomper::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    return other->type() == Zombie::Type && qFuzzyCompare(y(),other->y()) && qAbs(x() - other->x()) < 100;
}

QRectF Plant_Chomper::boundingRect() const
{
    return QRectF(-40, -60, 100, 100);
}
