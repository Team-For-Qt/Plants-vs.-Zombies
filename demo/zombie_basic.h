#ifndef ZOMBIE_BASIC_H
#define ZOMBIE_BASIC_H
#include "zombie.h"
#include <QMovie>


class Zombie_Basic : public Zombie
{
public:
    Zombie_Basic();
    void advance(int phase)override;
};

#endif // ZOMBIE_BASIC_H
