#ifndef SUNNER_H
#define SUNNER_H
#include "plant.h"
#include "energy.h"

class Sunner : public Plant
{
public:
    Sunner();
    void advance(int phase) override;
};

#endif // SUNNER_H
