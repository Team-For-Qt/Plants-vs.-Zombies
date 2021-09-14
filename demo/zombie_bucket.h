#ifndef ZOMBIE_BUCKET_H
#define ZOMBIE_BUCKET_H
#include "zombie.h"

class Zombie_Bucket : public Zombie
{
public:
    Zombie_Bucket();
    void advance(int phase)override;
};

#endif // ZOMBIE_BUCKET_H
