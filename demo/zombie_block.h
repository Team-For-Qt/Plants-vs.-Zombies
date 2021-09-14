#ifndef ZOMBIE_BLOCK_H
#define ZOMBIE_BLOCK_H
#include "zombie.h"

class Zombie_Block : public Zombie
{
public:
    Zombie_Block();
    void advance(int phase)override;
};

#endif // ZOMBIE_BLOCK_H
