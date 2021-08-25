#include "sun_num.h"

Sun_Num::Sun_Num()
{

}

void Sun_Num::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    painter->drawPixmap(QRect(-125,-15,176,98), QPixmap(":/image/images/BBB.png"));
}
