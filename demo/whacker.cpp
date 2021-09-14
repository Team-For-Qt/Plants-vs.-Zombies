#include "whacker.h"

Whacker::Whacker()
{
    judge = 0;
    speed = 20;
}

QRectF Whacker::boundingRect() const
{
    return QRectF(-30, -30, 60, 60);

}

void Whacker::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->drawPixmap(QRect(-30, -30, 60, 60), QPixmap(":/image/images/Whacker.png"));
}

bool Whacker::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode);
    return other->type() == Zombie::Type && qAbs(other->y() - y()) < 21 && qAbs(other->x() - x()) < 15;
}

void Whacker::advance(int phase)
{
    if(!phase)return;
    update();
    QList<QGraphicsItem *> items = collidingItems();
    if (!items.empty())
    {
        judge = 1;
        foreach (QGraphicsItem *item, items)
        {
            Zombie *zombie = qgraphicsitem_cast<Zombie *>(item);
            zombie->bv = 0;
        }
    }
    if(judge){
        setX(x()+speed);
    }
    if(x() > 999999)
        delete this;
}
