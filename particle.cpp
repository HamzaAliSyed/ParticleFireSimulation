#include "particle.h"
#include <stdlib.h>
#include <math.h>

namespace Hamza 
{
    Particle::Particle() : positionX(0), positionY(0)
    {
        particleDirection = (2.0 * M_PI* rand())/RAND_MAX;
        particleSpeed = (0.001 * rand())/RAND_MAX;
    }

    void Particle::Update(int interval)
    {
        double xSpeed = particleSpeed * cos(particleDirection);
        double ySpeed = particleSpeed * sin(particleDirection);

        positionX += xSpeed * interval;
        positionY += ySpeed * interval;

    }
}