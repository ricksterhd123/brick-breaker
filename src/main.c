#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <SDL.h>
#include <SDL_image.h>

#include "paddle.h"

int main(int argc, char *argv[])
{
    SDL_SetMainReady();

    SDL_Log("Initializing SDL");

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
    {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow(
        "An SDL2 window",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        640,
        480,
        SDL_WINDOW_OPENGL);

    if (window == NULL)
    {
        SDL_Log("Unable to initialize window: %s", SDL_GetError());
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
    {
        SDL_Log("Unable to initialize renderer: %s", SDL_GetError());
        return 1;
    }

    paddle paddle;
    paddle_create(&paddle, 0, 430, 255, 255, 255, 255, 100, 25);

    bool running = true;
    SDL_Event event;

    unsigned int deltaTime = 0;
    while (running)
    {
        unsigned int curTick = SDL_GetTicks();
        SDL_PollEvent(&event);

        if (event.type == SDL_QUIT)
        {
            SDL_Log("Program quit after %i ticks", event.quit.timestamp);
            running = false;
            break;
        } else if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_LEFT) {
                SDL_Log("Pressed left");
                paddle.velocity.x = -1;
            } else if (event.key.keysym.sym == SDLK_RIGHT) {
                SDL_Log("Pressed right");
                paddle.velocity.x = 1;
            } else if (event.key.keysym.sym == SDLK_SPACE) {
                SDL_Log("Pressed space");
                paddle.velocity.x = 0;
            }
        }

        // SDL_Log("Tick count: %i", SDL_GetTicks());

        // Update objects
        paddle_update(&paddle, window, deltaTime);


        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Draw objects
        paddle_draw(renderer, &paddle);
        SDL_RenderPresent(renderer);

        deltaTime = SDL_GetTicks() - curTick;
    }

    SDL_DestroyWindow(window);

    SDL_Log("Shutting down...");
    SDL_Quit();

    return 0;
}
