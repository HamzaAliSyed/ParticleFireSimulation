#include "particle.h"
#include <stdlib.h>

namespace Hamza 
{
    Particle::Particle() 
    {
        positionX = ((2.0*rand())/RAND_MAX) -1;
        positionY = ((2.0*rand())/RAND_MAX)-1;
    }
}