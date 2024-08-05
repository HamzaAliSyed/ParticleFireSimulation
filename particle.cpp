#include "particle.h"
#include <stdlib.h>

namespace Hamza 
{
    Particle::Particle() 
    {
        positionX = ((2.0*rand())/RAND_MAX) -1;
        positionY = ((2.0*rand())/RAND_MAX)-1;
        xSpeed = 0.01*(((2.0 * rand())/RAND_MAX)-1);
        ySpeed = 0.01*(((2.0 * rand())/RAND_MAX)-1);
    }

    void Particle::Update()
    {
        positionX+= xSpeed;
        positionY+= ySpeed;

        if (positionX <= -1 || positionX >= 1){
            xSpeed = -xSpeed;
        }

        if (positionY <= -1 || positionY >= 1){
            ySpeed = -ySpeed;
        }
    }
}