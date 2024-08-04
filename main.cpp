#include <iostream>
#include <SDL2/SDL.h>
#include "screen.h"
#include <math.h>


int main(int argc, char* argv[]){
    Hamza::Screen basicScreen;

    basicScreen.Init();
    while(basicScreen.running == true) {
        int elapsed = SDL_GetTicks();
		unsigned char red = (unsigned char)((1 + sin(elapsed * 0.0001)) * 128);
        unsigned char green = (unsigned char)((1 + sin(elapsed * 0.0003)) * 128);
        unsigned char blue = (unsigned char)((1 + sin(elapsed * 0.0005)) * 128);
        for(int y=0; y < basicScreen.HEIGHT; y++) {
			for(int x=0; x < basicScreen.WIDTH; x++) {
				basicScreen.SetPixels(x, y, red, green, blue);
			}
		}
        basicScreen.Update();
        basicScreen.ProcessEvents();
        if (basicScreen.ProcessEvents() == false) {
            basicScreen.Close();
        }


    }
    return 0;
}