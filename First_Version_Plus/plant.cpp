#include "plant.h"
#include<QMovie>

Plant::Plant()
{

}

void Plant::setMovie(QString path){
//    if (movie)
//        delete movie;
    movie = new QMovie(path);
    movie->start();
}

QRectF Plant::boundingRect() const
{
    return QRectF(-30, -30, 70, 70);
}


void Plant::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->drawImage(boundingRect(), movie->currentImage());
}
