#include <iostream>
#include <SDL2/SDL.h>
#include "screen.h"


int main(int argc, char* argv[]){
    Hamza::Screen basicScreen;

    basicScreen.Init();
    while(basicScreen.running == true) {
        basicScreen.ProcessEvents();
    }


    return 0;
}