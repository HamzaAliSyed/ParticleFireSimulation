#include "particle.h"
#include <stdlib.h>
#include <math.h>

namespace Hamza 
{
    Particle::Particle() : positionX(0), positionY(0)
    {
        particleDirection = (2.0 * M_PI* rand())/RAND_MAX;
        particleSpeed = (0.01 * rand())/RAND_MAX;
    }

    void Particle::Update()
    {
        double xSpeed = particleSpeed * cos(particleDirection);
        double ySpeed = particleSpeed * sin(particleDirection);

        positionX += xSpeed;
        positionY += ySpeed;

        if (positionX <= -1 || positionX >= 1){
            positionX -= xSpeed;
        }

        if (positionY <= -1 || positionY >= 1){
           positionY -= ySpeed;
        }
    }
}