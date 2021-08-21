#include "zombie.h"

Zombie::Zombie()
{

}
void Zombie::setMovie(QString path)
{
//    if (movie)
//        delete movie;
    movie = new QMovie(path);
    movie->start();
}
QRectF Zombie::boundingRect() const
{
    return QRectF(-80, -100, 200, 140);
}

void Zombie::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    movie->setSpeed(50);
    painter->drawImage(QRectF(-70, -100, 140, 140), movie->currentImage());

}
int Zombie::type() const
{
    return Type;
}
