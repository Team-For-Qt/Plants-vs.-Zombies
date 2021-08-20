#include "zombie_basic.h"

Zombie_Basic::Zombie_Basic()
{
    if (qrand() % 2)
        setMovie(":/image/images/ZombieWalk1.gif");
    else
        setMovie(":/image/images/ZombieWalk2.gif");
}

void Zombie_Basic::advance(int phase)
{
    if(!phase)return;
    update();
    setX(x()-0.5);
}
