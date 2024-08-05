#include "screen.h"
#include <iostream>

namespace Hamza {
        Screen::Screen() : window(NULL),renderer(NULL), texture(NULL), buffer(NULL),running(false) {

        }

        bool Screen::Init(){
            if (SDL_Init(SDL_INIT_EVERYTHING) == 0){
                std::cout << "SDL was successfully initialized" << std::endl;
                running = true;
                window = SDL_CreateWindow("Particle Explosion Demo", SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,WIDTH,HEIGHT,SDL_WINDOW_RESIZABLE);
                if (window == NULL){
                    std::cout << "Couldnt create window: " << SDL_GetError() << std::endl;
                } else {
                    std::cout << "Window was created successfully" << std::endl;
                }

                renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_PRESENTVSYNC);
                texture = SDL_CreateTexture(renderer,SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_STATIC,WIDTH,HEIGHT);
                buffer = new Uint32[WIDTH * HEIGHT];
                memset(buffer,0x00,WIDTH*HEIGHT*sizeof(Uint32));
                return true;
            } else {
                std::cout << "SDL failed to initialize" << std::endl;
                return false;
            }
        }

        void Screen::Update(){
            SDL_UpdateTexture(texture,NULL,buffer,WIDTH * sizeof(Uint32));
            SDL_RenderClear(renderer);
            SDL_RenderCopy(renderer,texture,NULL,NULL);
            SDL_RenderPresent(renderer);
        }

        void Screen::SetPixels(int x, int y, Uint8 red, Uint8 green, Uint8 blue){

            if(x < 0 || x >= WIDTH || y < 0 || y>= HEIGHT){
                return;
            }
            Uint32 color;
            color += red;
            color <<= 8;
            color += green;
            color <<=8;
            color += blue;
            color <<=8;

            buffer[(y*WIDTH)+x] = color; 
        }

        bool Screen::ProcessEvents(){
            SDL_Event windowEvent;
            if (SDL_PollEvent(&windowEvent)){
                if (windowEvent.type == SDL_QUIT) {
                    return false;
                }
            }
            return true;
        }

        void Screen::Close(){
            running = false;
            delete []buffer;
            SDL_DestroyTexture(texture);
            SDL_DestroyRenderer(renderer);
            SDL_DestroyWindow(window);
            SDL_Quit();

        }
};