#include "draw.h"

void setDrawColor(SDL_Renderer *renderer, SDL_Color &color)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
}