#include "draw.h"
#include "main.h"
#include <iostream>

int main(int argc, char *argv[])
{
    AppState state;
    SDL_Init(SDL_INIT_VIDEO);
    state.window = SDL_CreateWindow("Win31", 1280, 1024, SDL_WINDOW_RESIZABLE | SDL_WINDOW_BORDERLESS);
    if (state.window == nullptr)
    {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    state.renderer = SDL_CreateRenderer(state.window, NULL);
    SDL_SetRenderScale(state.renderer, state.scale, state.scale);
    if (state.renderer == nullptr)
    {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(state.window);
        SDL_Quit();
        return 1;
    }

    SDL_Event e;
    bool quit = false;

    while (!quit)
    {
        while (SDL_WaitEventTimeout(&e, 16))
        {
            std::cout << "event: " << e.type << std::endl;
            switch (e.type)
            {
            case SDL_EVENT_QUIT:
                quit = true;
                break;
            default:
                render(&state);
                break;
            }
        }
    }

    SDL_DestroyRenderer(state.renderer);
    SDL_DestroyWindow(state.window);
    SDL_Quit();

    return 0;
}

void render(AppState *state)
{
    static float border = state->borderSize;
    static SDL_Rect size;
    static SDL_FRect scaledSize;
    SDL_GetWindowSize(state->window, &size.w, &size.h);

    setDrawColor(state->renderer, White);
    SDL_RenderClear(state->renderer); // Clear the renderer

    scaledSize.w = size.w / state->scale;
    scaledSize.h = size.h / state->scale;

    static SDL_FRect outerBorder = {0, 0, scaledSize.w, scaledSize.h};
    static SDL_FRect topGray = {1, 1, scaledSize.w - 2, border};
    static SDL_FRect bottomGray = {1, scaledSize.h - border - 1, scaledSize.w - 2, border};
    static SDL_FRect sideGrayLeft = {1, 1 + border, border, scaledSize.h - 2 * border - 2};
    static SDL_FRect sideGrayRight = {scaledSize.w - border - 1, 1 + border, border, scaledSize.h - 2 * border - 2};
    static SDL_FRect innerBorder = {border + 1, border + 1, scaledSize.w - 2 * border - 2, scaledSize.h - 2 * border - 2};

    setDrawColor(state->renderer, Black);
    SDL_RenderRect(state->renderer, &outerBorder);

    setDrawColor(state->renderer, Gray);
    SDL_RenderFillRect(state->renderer, &topGray);
    SDL_RenderFillRect(state->renderer, &bottomGray);
    SDL_RenderFillRect(state->renderer, &sideGrayLeft);
    SDL_RenderFillRect(state->renderer, &sideGrayRight);
    setDrawColor(state->renderer, Black);
    SDL_RenderRect(state->renderer, &innerBorder);

    float tickPosition = 1 + border + state->buttonSize;

    // horizontal ticks
    SDL_RenderLine(state->renderer, 1, tickPosition, border, tickPosition);                                       // top left
    SDL_RenderLine(state->renderer, scaledSize.w - border - 1, tickPosition, scaledSize.w - 2, tickPosition);     // top right
    SDL_RenderLine(state->renderer, 1, scaledSize.h - 2 - tickPosition, border, scaledSize.h - 2 - tickPosition); // bottom left
    SDL_RenderLine(state->renderer, scaledSize.w - border - 1, scaledSize.h - 2 - tickPosition,
                   scaledSize.w - 2, scaledSize.h - 2 - tickPosition); // bottom right

    // verticalTicks
    SDL_RenderLine(state->renderer, tickPosition, 1, tickPosition, border);                                   // top left
    SDL_RenderLine(state->renderer, tickPosition, scaledSize.h - border - 1, tickPosition, scaledSize.h - 2); // bottom left

    SDL_RenderLine(state->renderer, scaledSize.w - 2 - tickPosition, 1, scaledSize.w - 2 - tickPosition, border); // top right
    SDL_RenderLine(state->renderer, scaledSize.w - 2 - tickPosition, scaledSize.h - border - 1,
                   scaledSize.w - 2 - tickPosition, scaledSize.h - 2); // bottom right

    setDrawColor(state->renderer, Magenta);
    SDL_RenderPresent(state->renderer);
}