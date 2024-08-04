#pragma once
#include <SDL2/SDL.h>

namespace Hamza {
    class Screen {
        private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        SDL_Texture *texture;
        Uint32 *buffer;

        public:
        const static int WIDTH = 1280;
        const static int HEIGHT = 720;
        bool running;
        Screen();
        void Close();
        bool ProcessEvents();
        bool Init();
    };
}