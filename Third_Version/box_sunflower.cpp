#include "box_sunflower.h"
#include <QtWidgets>
#include<QDrag>

Box_SunFlower::Box_SunFlower()
{
    name = "SunFlower";
    cost = 50;
}

//void Box_SunFlower::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
//{
//    QDrag *drag = new QDrag(event->widget());
//    QMimeData *mime = new QMimeData;
//    drag->setMimeData(mime);

//    QString S = ":/image/images/" + name1 + ".png";
//    qDebug() << S;

//    QImage image(PATH);
//    //:/image/images/Plant_Chomper.png
//    mime->setImageData(image);

//    drag->setPixmap(QPixmap::fromImage(image).scaled(120, 100));
//    drag->setHotSpot(QPoint(15, 30));

//    drag->exec();
//    setCursor(Qt::OpenHandCursor);
//}
