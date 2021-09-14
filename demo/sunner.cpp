#include "sunner.h"
#include <QDebug>
#include "energy.h"
Sunner::Sunner()
{
    bv=300;
    cnt=0;
    time=50;
    setMovie(":/image/images/Sunnnner.gif");
}

void Sunner::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (bv <= 0)
        delete this;
    else if (++cnt >= time)
    {
        cnt = 0;
        scene()->addItem(new Energy(pos()));
    }
}

