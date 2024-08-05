#include "swarm.h"

namespace Hamza 
{
    Swarm::Swarm(){
        pointerParticlesArray = new Particle[MAXPARTICLES];
    }



    Swarm::~Swarm(){
        delete []pointerParticlesArray;
    }
}