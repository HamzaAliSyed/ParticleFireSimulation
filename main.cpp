#include <iostream>
#include <SDL2/SDL.h>

const int WIDTH = 1280, HEIGHT = 720;

bool quit = false;

int main(int argc, char* argv[]){
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *window = SDL_CreateWindow("Particle Explosion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,WIDTH,HEIGHT,SDL_WINDOW_RESIZABLE);

    if (NULL == window) {
        std::cout << "Could not create window" << SDL_GetError() << std::endl;
        return 1;
    } else {
        std::cout << "Successfully created window" << std::endl;
    }

    SDL_Event windowEvent;
    SDL_Renderer *windowRenderer = SDL_CreateRenderer(window, -1,SDL_RENDERER_PRESENTVSYNC);
    SDL_Texture *windowTexture = SDL_CreateTexture(windowRenderer,SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_STATIC,WIDTH,HEIGHT);
    Uint32 *buffer = new Uint32[WIDTH * HEIGHT];
    memset(buffer,0xFF,WIDTH*HEIGHT*sizeof(Uint32));
    SDL_UpdateTexture(windowTexture,NULL,buffer,WIDTH * sizeof(Uint32));
    SDL_RenderClear(windowRenderer);
    SDL_RenderCopy(windowRenderer,windowTexture,NULL,NULL);
    SDL_RenderPresent(windowRenderer);

    if (windowRenderer == NULL) {
        std::cout << "Renderer creation failed" << std::endl;
        return 1;
    } else {
        std::cout << "Renderer created successfully" << std::endl;
    }

    if (windowTexture == NULL) {
        std::cout << "Texture creation failed" << std::endl;
        return 1;
    } else {
        std::cout << "Texture created successfully" << std::endl;
    }

    while(quit != true)
    {
        if (SDL_PollEvent(&windowEvent)){
            if (SDL_QUIT == windowEvent.type)
            {
                quit = true;
            }
        }
    }

    delete [] buffer;
    SDL_DestroyTexture(windowTexture);
    SDL_DestroyRenderer(windowRenderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}