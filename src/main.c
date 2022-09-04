#include <stdio.h>
#include <sdl.h>
#include "test.h"

int main(int argc, char* argv[])
{
    printf("Hello World\n");
    printf("%d\n", yes());

    SDL_SetMainReady();

    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    }

    /* ... */

    SDL_Quit();

    return 0;
}
