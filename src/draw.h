#ifndef DRAW_H
#define DRAW_H
#include <SDL3/SDL.h>

extern SDL_Color Black;
extern SDL_Color White;
extern SDL_Color Gray;
extern SDL_Color Blue;
extern SDL_Color Red;
extern SDL_Color Magenta;

void setDrawColor(SDL_Renderer *renderer, SDL_Color &color);

#endif // DRAW_H