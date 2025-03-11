#ifndef MAIN_H
#define MAIN_H

#include <SDL3/SDL.h>

typedef struct
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    float scale = 2;
    float borderSize = 2;
    float buttonSize = 18;
} AppState;

void render(AppState *state);

#endif // MAIN_H