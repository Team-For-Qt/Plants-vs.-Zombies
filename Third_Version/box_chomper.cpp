#include "box_chomper.h"
#include <QtWidgets>
#include<QDrag>

Box_Chomper::Box_Chomper()
{
    name = "Chomper";
    cost = 100;
}

//void Box_Chomper::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
//{
//    QDrag *drag = new QDrag(event->widget());
//    QMimeData *mime = new QMimeData;
//    drag->setMimeData(mime);
//    mime->setText(name);


//    QString S = ":/image/images/Plant_Chomper.png";
//    qDebug() << S;

//    QImage image(":/image/images/Plant_Chomper.png");
//    //:/image/images/Plant_Chomper.png

//    drag->setPixmap(QPixmap::fromImage(image).scaled(120, 100));
//    drag->setHotSpot(QPoint(40, 45));

//    drag->exec();
//    setCursor(Qt::OpenHandCursor);
//}


