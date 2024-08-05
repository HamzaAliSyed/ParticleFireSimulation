#include "particle.h"
#include <stdlib.h>
#include <math.h>

namespace Hamza 
{
    Particle::Particle() : positionX(0), positionY(0)
    {
        Init();
    }

    void Particle::Init() {
        positionX = 0;
        positionY = 0;
        particleDirection = (2 * M_PI * rand())/RAND_MAX;
        particleSpeed = (0.04 * rand())/RAND_MAX;
        particleSpeed *= particleSpeed;
    }

    void Particle::Update(int interval)
    {
        particleDirection += interval * 0.0013;
        double xSpeed = particleSpeed * cos(particleDirection);
        double ySpeed = particleSpeed * sin(particleDirection);

        positionX += xSpeed * interval;
        positionY += ySpeed * interval;

        if (positionX < -1 || positionX > 1 || positionY < -1 || positionY > 1) {
		Init();
	}

    if(rand() < RAND_MAX/100) {
		Init();
	}

    }
}