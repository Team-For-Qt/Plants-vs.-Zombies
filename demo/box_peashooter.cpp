#include "box_peashooter.h"
#include <QtWidgets>
#include<QDrag>

Box_Peashooter::Box_Peashooter()
{
    name = "Peashooter";
    cost = 125;
}

//void Box_Peashooter::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
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
