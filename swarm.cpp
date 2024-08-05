#include "swarm.h"

namespace Hamza 
{
    Swarm::Swarm(){
        pointerParticlesArray = new Particle[MAXPARTICLES];
    }

    void Swarm::UpdateSwarm(){
        for(int i = 0; i < MAXPARTICLES; i++){
            pointerParticlesArray[i].Update();
        }
    }

    Swarm::~Swarm(){
        delete []pointerParticlesArray;
    }
}