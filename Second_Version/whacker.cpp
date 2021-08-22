#include "whacker.h"

Whacker::Whacker()
{

}

QRectF Whacker::boundingRect() const
{
    return QRectF(-500, -300, 300, 300);

}

void Whacker::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->drawPixmap(QRect(-30, -30, 60, 60), QPixmap(":/image/images/Whacker.png"));
}
