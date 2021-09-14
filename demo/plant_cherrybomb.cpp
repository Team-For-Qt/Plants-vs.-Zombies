#include "plant_cherrybomb.h"

Plant_CherryBomb::Plant_CherryBomb()
{
    setMovie(":/image/images/CherryBomb.gif");
    condition = 0;
    int cnt=0;
    int time=100;
}

QRectF Plant_CherryBomb::boundingRect() const
{
    if(condition)
    {
        return QRectF(-44, -30, 100, 70);
    }
    else
    {
        return Plant::boundingRect();
    }
}

void Plant_CherryBomb::advance(int phase)
{
    if(!phase)
        return;
    update();
    cnt++;
    if(!condition && movie->currentFrameNumber() == movie->frameCount() - 1)
    {
        condition = 1;
        setMovie(":/image/images/Boom.gif");
        QList<QGraphicsItem *> items = collidingItems();
        foreach (QGraphicsItem *item, items)
        {
            Zombie *zombie = qgraphicsitem_cast<Zombie *>(item);
            zombie->speed=0;
            zombie->bv = -100;
            zombie->setMovie(":/image/images/Burn.gif");
            zombie->condition =0;
        }
    }
    else if (condition == 1 && movie->currentFrameNumber() == movie->frameCount() - 1)
        delete this;

}

bool Plant_CherryBomb::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode);
    return other->type()==Zombie::Type && other->y() < y() + 105 && other->y() > y() - 105 && other->x() > x() - 85 && other->x() < x() + 85;
}
