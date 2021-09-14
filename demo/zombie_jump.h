#ifndef ZOMBIE_JUMP_H
#define ZOMBIE_JUMP_H
#include "zombie.h"

class Zombie_Jump : public Zombie
{
public:
    Zombie_Jump();
    void advance(int phase)override;
//    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
};

#endif // ZOMBIE_JUMP_H
