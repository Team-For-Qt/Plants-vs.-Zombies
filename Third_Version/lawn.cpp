#include "lawn.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "zombie_basic.h"
#include "zombie.h"
#include "plant.h"
#include "plant_pea.h"
#include "weapon.h"
#include "weapon_pea.h"
#include "messy.h"
#include "whacker.h"
#include "sun_num.h"
#include "plant_chomper.h"
#include "plant_shield.h"
#include "box_chomper.h"
#include "box_peashooter.h"
#include "plant_groundattack.h"
#include "box_grounattack.h"
#include "box_sunflower.h"
#include "box_snowpea.h"
#include "lawn.h"
#include "box_shield.h"
#include "box_cherrybomb.h"

#include "plant_peasnow.h"
#include<qgraphicsitem.h>
#include <QSound>

#include "box.h"

Lawn::Lawn()
{
    const static QMap<QString, int> map;
    dragOver = false;
    setAcceptDrops(true);
}

QRectF Lawn::boundingRect() const
{
    return QRectF(0, 0, 750, 500);
}

void Lawn::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(painter);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Lawn::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
    if (event->mimeData()->hasText()) {
        event->setAccepted(true);
        dragOver = true;
        update();
    } else {
        event->setAccepted(false);
    }
}

void Lawn::dragLeaveEvent(QGraphicsSceneDragDropEvent *event)
{
    Q_UNUSED(event);
    dragOver = false;
    update();

}

void Lawn::dropEvent(QGraphicsSceneDragDropEvent *event)
{
    dragOver = false;
    if (event->mimeData()->hasText())
    {
        QString name =event->mimeData()->text();
        QPointF pos = mapToScene(event->pos());
        int a = int(pos.x() - 545) / 82 * 82 + 570;
        int b = int(pos.y() - 190) / 100 * 100 + 215;

//        int x = (a - 570) / 82;
//        int y = (b - 215) / 100;

//        if(map[x][y])
//            goto stop;

        if(name == "Peashooter"){
            Plant *p = new Plant_Pea;
            p->setPos(a,b);
            scene()->addItem(p);
        }
        if(name == "Chomper"){
            Plant *p =new Plant_Chomper;
            p->setPos(a,b);
            scene()->addItem(p);
        }
        if(name == "Shield"){
            Plant *p = new Plant_shield;
            p->setPos(a,b);
            scene()->addItem(p);
        }
        //if(name == "SunFlower")
        if(name == "SnowPea")  {
            Plant *p = new Plant_PeaSnow;
            p->setPos(a,b);
            scene()->addItem(p);
        }
        if(name == "GroundAttack"){
            Plant *p = new Plant_GroundAttack;
            p->setPos(a,b);
            scene()->addItem(p);
        }
//        map[x][y] = 1;
    }
//    stop:;
    update();
}
