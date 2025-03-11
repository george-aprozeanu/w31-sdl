#ifndef MAIN_H
#define MAIN_H

#include "draw.h"
#include <SDL3/SDL.h>

class AppState
{
public:
    SDL_Window *window;
    Renderer sdl;
    float scale;
    float borderSize;
    float buttonSize;
    AppState(SDL_Window *window, SDL_Renderer *sdl_renderer)
        : window(window), sdl(sdl_renderer), scale(2), 
        borderSize(2), buttonSize(18) {}
};

void render(AppState &state);

#endif // MAIN_H