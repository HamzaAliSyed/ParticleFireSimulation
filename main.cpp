#include <iostream>
#include <SDL2/SDL.h>
#include "screen.h"


int main(int argc, char* argv[]){
    Hamza::Screen basicScreen;

    basicScreen.Init();
    for(int i=0; i < basicScreen.HEIGHT;i++){
        for (int j=0; j < basicScreen.WIDTH;j++){
            basicScreen.SetPixels(j,i,128,55,255);
        }
    }
    basicScreen.SetPixels(640,360,0,0,0);
    basicScreen.Update();
    while(basicScreen.running == true) {
        basicScreen.ProcessEvents();
    }


    return 0;
}