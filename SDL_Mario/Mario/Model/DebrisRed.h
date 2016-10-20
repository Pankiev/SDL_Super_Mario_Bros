

#include "Debris.h"

class DebrisRed : public Debris
{
public:

    DebrisRed(MarioGame& game, float upwardForce, int horizontalDirection);

    void setLookout() override;
};
