#include "box_grounattack.h"
#include <QtWidgets>
#include<QDrag>

Box_GrounAttack::Box_GrounAttack()
{
    name = "GroundAttack";
    cost = 200;
}

void Box_GrounAttack::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (QLineF(event->screenPos(), event->buttonDownScreenPos(Qt::LeftButton)).length()
            < QApplication::startDragDistance())
        return;
    QDrag *drag = new QDrag(event->widget());
    QMimeData *mime = new QMimeData;
    mime->setText(name);
    drag->setMimeData(mime);
    QImage image(":/image/images/Plant_GroundAttack.png");
    mime->setImageData(image);
    mime->setText(name);

    drag->setPixmap(QPixmap::fromImage(image).scaled(90, 50));
    drag->setHotSpot(QPoint(35, 35));

    drag->exec();
    setCursor(Qt::OpenHandCursor);
}
