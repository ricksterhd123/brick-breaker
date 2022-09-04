#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <SDL.h>
#include <SDL_image.h>

#include "test.h"

int main(int argc, char* argv[])
{
    SDL_SetMainReady();

    SDL_Log("Initializing SDL");

    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow(
        "An SDL2 window",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        640,
        480,
        SDL_WINDOW_OPENGL
    );

    if (window == NULL) {
        SDL_Log("%s", SDL_GetError());
        return 1;
    }

    bool running = true; 
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                SDL_Log("Program quit after %i ticks", event.quit.timestamp);
                running = false;
                break;
            }
        }
    }

    SDL_DestroyWindow(window);

    SDL_Log("Shutting down...");
    SDL_Quit();

    return 0;
}
