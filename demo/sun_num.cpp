#include "sun_num.h"
#include "energy.h"
#include "QDebug"
Sun_Num::Sun_Num()
{
    sun = 25;
}

void Sun_Num::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    painter->drawPixmap(QRect(-125,-15,176,98), QPixmap(":/image/images/BBB.png"));
    QFont font;
    font.setPointSizeF(30);
    painter->setFont(font);
    painter->drawText(-60, 50, QString().sprintf("%3d", sun));
}

void Sun_Num::advance(int phase)
{
    if(!phase)
        return;
    update();
    static int cnt =0;
    static int time = 200;
    if(!(cnt%20))
    {
        qDebug()<<cnt;
    }
    if(cnt++>time)
    {
        cnt =0;
        scene()->addItem(new Energy);
    }
}
