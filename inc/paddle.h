#pragma once
#include <SDL.h>
#include "rgb.h"
#include "vector2.h"

typedef struct paddle
{
    vector2 position;
    vector2 velocity;
    RGBA colour;
    vector2 size;
} paddle;

void paddle_create(
    paddle* paddle,
    unsigned int x,
    unsigned int y,
    unsigned int r,
    unsigned int g,
    unsigned int b,
    unsigned int a,
    unsigned int width,
    unsigned int height
)
{
    paddle->position.x = x;
    paddle->position.y = y;
    paddle->colour.r = r;
    paddle->colour.g = g;
    paddle->colour.b = b;
    paddle->colour.a = a;
    paddle->size.x = width;
    paddle->size.y = height;
    paddle->velocity.x = 0;
    paddle->velocity.y = 0;
}

void paddle_draw(SDL_Renderer* renderer, paddle* paddle)
{
    SDL_Rect block;
    block.x = paddle->position.x;
    block.y = paddle->position.y;
    block.w = paddle->size.x;
    block.h = paddle->size.y;

#ifdef DEBUG
    SDL_Log("x: %i, y: %i, r: %i, g: %i, b: %i, a: %i, w: %i, h: %i",
        paddle->position.x,
        paddle->position.y,
        paddle->colour.r,
        paddle->colour.g,
        paddle->colour.b,
        paddle->colour.a,
        paddle->size.x,
        paddle->size.y
    );
#endif

    SDL_SetRenderDrawColor(renderer, paddle->colour.r, paddle->colour.g, paddle->colour.b, paddle->colour.a);
    SDL_RenderFillRect(renderer, &block);
}

void paddle_update(paddle* paddle, SDL_Window* window, unsigned int deltaTime)
{
    int screenWidth, screenHeight;
    SDL_GetWindowSize(window, &screenWidth, &screenHeight);

    // SDL_Log("%i, %i, %i. %i", screenHeight, screenWidth, (screenWidth - paddle->size.x), paddle->size.x);

    paddle->position.x = paddle->position.x + paddle->velocity.x * deltaTime;
    paddle->position.y = paddle->position.y + paddle->velocity.y * deltaTime;

    if (paddle->position.x < 0) {
        paddle->position.x = 0;
    } else if (paddle->position.x > (screenWidth - paddle->size.x)) {
        paddle->position.x = screenWidth - paddle->size.x;
    }
}
