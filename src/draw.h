#ifndef DRAW_H
#define DRAW_H
#include <SDL3/SDL.h>

SDL_Color Black = {0, 0, 0, 0xff};
SDL_Color White = {0xff, 0xff, 0xff, 0xff};
SDL_Color Gray = {0xc0, 0xc0, 0xc0, 0xff};
SDL_Color Blue = {0, 0, 0x80, 0xff};
SDL_Color Red = {0x80, 0, 0x0, 0xff};
SDL_Color Magenta = {0x80, 0, 0x80, 0xff};

void setDrawColor(SDL_Renderer *renderer, SDL_Color &color);

#endif // DRAW_H