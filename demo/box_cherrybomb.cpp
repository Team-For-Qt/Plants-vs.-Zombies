#include "box_cherrybomb.h"
#include <QtWidgets>
#include<QDrag>

Box_CherryBomb::Box_CherryBomb()
{
    name = "CherryBomb";
    cost = 200;
}

//void Box_CherryBomb::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
//{
//    if (QLineF(event->screenPos(), event->buttonDownScreenPos(Qt::LeftButton)).length()
//            < QApplication::startDragDistance())
//        return;
//    QDrag *drag = new QDrag(event->widget());
//    QMimeData *mime = new QMimeData;
//    drag->setMimeData(mime);

//    QString S = ":/image/images/" + name1 + ".png";
//    qDebug() << S;

//    QImage image(PATH);
//    //:/image/images/Plant_Chomper.png
//    mime->setImageData(image);

//    drag->setPixmap(QPixmap::fromImage(image).scaled(120, 100));
//    drag->setHotSpot(QPoint(35, 35));

//    drag->exec();
//    setCursor(Qt::OpenHandCursor);

//}
