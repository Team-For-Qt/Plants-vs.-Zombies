#include "energy.h"
#include <QMovie>
#include "sun_num.h"
#include "mainwindow.h"
#include <QGraphicsSceneMouseEvent>

Energy::Energy()
{
    dtn = QPointF(290 + qrand() % (82 * 7), 130 + qrand() % (98 * 5));
    setPos(QPointF(dtn.x(), 70));
    speed = 60.0 * 50 / 1000;
    cnt = 0;
    time = int(10);
    movie = new QMovie(":/image/images/Energy.gif");
    movie->start();
    setAcceptedMouseButtons(Qt::LeftButton);
}

Energy::Energy(QPointF pos)
{
    dtn = QPointF(pos.x() + qrand() % 30 - 15, pos.y() + qrand() % 30 + 15);
    setPos(QPointF(dtn.x(), pos.y()));
    speed = 60 * 50 / 1000;
    cnt = 0;
    time = int(10.0 * 1000 / 33);
    movie = new QMovie(":/image/images/Energy.gif");
    movie->start();
    setAcceptedMouseButtons(Qt::LeftButton);
}

Energy::~Energy()
{
    if (movie)
        delete movie;
}

QRectF Energy::boundingRect() const
{
    return QRectF(-35, -35, 70, 70);
}

void Energy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->drawImage(boundingRect(), movie->currentImage());
}

void Energy::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)
    Sun_Num *tou = qgraphicsitem_cast<Sun_Num *>(scene()->items(QPointF(300, 15))[0]);
    tou->sun += 25;
    cnt = time;
    event->setAccepted(true);
}

void Energy::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (++cnt >= time)
        delete this;
    else if (y() < dtn.y())
        setY(y() + speed);
}
