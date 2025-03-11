#ifndef DRAW_H
#define DRAW_H
#include <SDL3/SDL.h>

extern SDL_Color Black;
extern SDL_Color White;
extern SDL_Color Gray;
extern SDL_Color Blue;
extern SDL_Color Red;
extern SDL_Color Magenta;

class Renderer
{
public:
    Renderer(SDL_Renderer *renderer) : renderer(renderer) {}

    bool drawColor(SDL_Color &color)
    {
        return SDL_SetRenderDrawColor(this->renderer, color.r, color.g, color.b, color.a);
    }

    bool clear()
    {
        return SDL_RenderClear(this->renderer);
    }

    bool rect(SDL_FRect &rect)
    {
        return SDL_RenderRect(this->renderer, &rect);
    }

    bool line(float x1, float y1, float x2, float y2)
    {
        return SDL_RenderLine(this->renderer, x1, y1, x2, y2);
    }

    bool present()
    {
        return SDL_RenderPresent(this->renderer);
    }

private:
    SDL_Renderer *renderer;
};

#endif // DRAW_H