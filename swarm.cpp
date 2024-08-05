#include "swarm.h"

namespace Hamza 
{
    Swarm::Swarm(): lastTime(0){
        pointerParticlesArray = new Particle[MAXPARTICLES];
    }

    void Swarm::UpdateSwarm(int timeElasped){
        int interval = timeElasped - lastTime;
        for(int i = 0; i < MAXPARTICLES; i++){
            pointerParticlesArray[i].Update(interval);
        }
        lastTime = timeElasped;
    }

    Swarm::~Swarm(){
        delete []pointerParticlesArray;
    }
}