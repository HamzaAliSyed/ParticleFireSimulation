#include <iostream>
#include <SDL2/SDL.h>
#include "screen.h"
#include "particle.h"
#include "swarm.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char* argv[]){
    srand(time(NULL));
    Hamza::Screen basicScreen;

    Hamza::Swarm mainSwarm;
    basicScreen.Init();
    
    while(basicScreen.running == true) {
        const Hamza::Particle* const pointerParticles = mainSwarm.getParticles();
        int elapsedTime = SDL_GetTicks();
        basicScreen.Clear();
        mainSwarm.UpdateSwarm();
        unsigned char red = (1+sin(elapsedTime*0.001)*128);
        unsigned char green = (1+sin(elapsedTime*0.005)*128);
        unsigned char blue = (1+sin(elapsedTime*0.009)*128);

        for (int i=0; i<mainSwarm.MAXPARTICLES;i++){
            Hamza::Particle individualParticle = pointerParticles[i];
            int posx = (individualParticle.positionX + 1 ) * basicScreen.WIDTH/2;
            int posy = (individualParticle.positionY + 1 ) * basicScreen.HEIGHT/2;
            basicScreen.SetPixels(posx,posy,red,blue,green);
        }
        basicScreen.Update();
        basicScreen.ProcessEvents();
        if (basicScreen.ProcessEvents() == false) {
            basicScreen.Close();
        }


    }
    return 0;
}