#pragma once
#include "particle.h"

namespace Hamza 
{
    class Swarm {
        private:
        Particle *pointerParticlesArray;
        int lastTime;
        public:
        const static int MAXPARTICLES = 25000;
        Swarm();
        const Particle* const getParticles() {return pointerParticlesArray;};
        void UpdateSwarm(int timeElasped);
        ~Swarm();
    };

}