#include "weapon.h"
#include "zombie.h"
#include <QDebug>

Weapon::Weapon()
{

}

QRectF Weapon::boundingRect() const
{
    return QRectF(-12, -28, 24, 24);
}

void Weapon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    if(!frozen)
        painter->drawPixmap(QRect(-12, -28, 24, 24), QPixmap(":/image/images/Pea.png"));
    else
        painter->drawPixmap(QRect(-12, -28, 24, 24), QPixmap(":/image/images/PeaSnow.png"));

}

bool Weapon::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode);
    return other->type() == Zombie::Type && qFuzzyCompare(other->y(), y()) && qAbs(other->x() - x()) < 30;
}

void Weapon::advance(int phase)
{
    if(!phase)
        return;
    update();
    QList<QGraphicsItem *> items = collidingItems();
    if (!items.isEmpty())
    {
        Zombie *zombie = qgraphicsitem_cast<Zombie *>(items[qrand() % items.size()]);
        zombie->bv -= ht;
        if (frozen && zombie->speed > 0.55)
            zombie->speed /= 2;
        delete this;
        return;
    }
    setX(x() + speed);
    if (x() > 1200)
        delete this;
}
