
#include "Debris.h"

class DebrisBlue : public Debris
{
public:

    DebrisBlue(MarioGame& game, float upwardForce, int horizontalDirection);
    void setLookout() override;
};
