#include "screen.h"
#include <iostream>

namespace Hamza {
        Screen::Screen() : window(NULL),renderer(NULL), texture(NULL), buffer(NULL),running(false), blurBuffer(NULL) {

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
                blurBuffer = new Uint32[WIDTH * HEIGHT];
                memset(buffer,0x00,WIDTH*HEIGHT*sizeof(Uint32));
                memset(blurBuffer,0x00,WIDTH*HEIGHT*sizeof(Uint32));
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


        void Screen::BoxBlur(){
            Uint32 *temp = buffer;
            buffer = blurBuffer;
            blurBuffer = temp;

            for (int y=0; y<Screen::HEIGHT;y++) {
                for (int x=0; x<Screen::WIDTH;x++) {
                    int redTotal = 0;
                    int greenTotal = 0;
                    int blueTotal = 0;

                    for(int row = -1; row <=1;row++){
                        for(int col = -1; col <=1;col++){
                            int currentX = x + col;
                            int currentY = y +row;

                            if(currentX >=0 && currentX < WIDTH && currentY >=0 && currentY <HEIGHT){
                                Uint32 color = blurBuffer[currentY * WIDTH + currentX];
                                Uint8 red = color >> 24;
                                Uint8 green = color >> 16;
                                Uint8 blue = color >> 8;

                                redTotal += red;
                                greenTotal += green;
                                blueTotal += blue;
                            }
                        }
                    }
                    Uint8 red = redTotal/9;
                    Uint8 green = greenTotal/9;
                    Uint8 blue = blueTotal/9;
                    SetPixels(x,y,red,green,blue);
                }
            }
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
            delete []blurBuffer;
            SDL_DestroyTexture(texture);
            SDL_DestroyRenderer(renderer);
            SDL_DestroyWindow(window);
            SDL_Quit();

        }
};