#include "box.h"

#include <QtWidgets>

Box::Box()
{
    setCursor(Qt::OpenHandCursor);
    setAcceptedMouseButtons(Qt::LeftButton);
}

QRectF Box::boundingRect() const
{
    return QRectF(-190,-30,250,140);
}

void Box::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->scale(.6, .58);
    painter->drawPixmap(QRect(-190,-30,250,140), QPixmap(":/image/images/Box_" + name + ".png"));
//    painter->drawPixmap(QRect(-190,-30,250,140), QPixmap(":/image/images/BBB.png"));
    QFont font;
    font.setPointSizeF(15);
    painter->setFont(font);
    painter->drawText(-30, 90, QString().sprintf("%3d", cost));
//    if (counter < cool[map[text]])
//    {
//        QBrush brush(QColor(0, 0, 0, 200));
//        painter->setBrush(brush);
//        painter->drawRect(QRectF(-48, -68, 98, 132 * (1 - qreal(counter) / cool[map[text]])));
    //    }
}

void Box::advance(int phase)
{
    if(!phase)return;
    update();
}

void Box::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    setCursor(Qt::ClosedHandCursor);
}

void Box::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (QLineF(event->screenPos(), event->buttonDownScreenPos(Qt::LeftButton)).length()
            < QApplication::startDragDistance())
        return;
    QDrag *drag = new QDrag(event->widget());
    QMimeData *mime = new QMimeData;


    QImage image(":/image/images/Plant_" + name + ".png");
    mime->setImageData(image);
    mime->setText(name);
    drag->setPixmap(QPixmap::fromImage(image).scaled(90, 80));
    drag->setHotSpot(QPoint(35, 35));
    drag->setMimeData(mime);


    drag->exec();
    setCursor(Qt::OpenHandCursor);
}



void Box::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    setCursor(Qt::OpenHandCursor);
}
