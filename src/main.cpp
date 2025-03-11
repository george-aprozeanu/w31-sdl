#include "main.h"
#include <iostream>

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    auto window = SDL_CreateWindow("Win31", 1280, 1024, SDL_WINDOW_RESIZABLE | SDL_WINDOW_BORDERLESS);
    if (window == nullptr)
    {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    auto scale = 2;
    auto renderer = SDL_CreateRenderer(window, NULL);
    SDL_SetRenderScale(renderer, scale, scale);

    AppState state(window, renderer);

    if (renderer == nullptr)
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
                render(state);
                break;
            }
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

void render(AppState &state)
{
    static float border = state.borderSize;
    static SDL_Rect size;
    static SDL_FRect scaledSize;
    SDL_GetWindowSize(state.window, &size.w, &size.h);

    state.sdl.drawColor(White);
    state.sdl.clear();

    scaledSize.w = size.w / state.scale;
    scaledSize.h = size.h / state.scale;

    static SDL_FRect outerBorder = {0, 0, scaledSize.w, scaledSize.h};
    static SDL_FRect topGray = {1, 1, scaledSize.w - 2, border};
    static SDL_FRect bottomGray = {1, scaledSize.h - border - 1, scaledSize.w - 2, border};
    static SDL_FRect sideGrayLeft = {1, 1 + border, border, scaledSize.h - 2 * border - 2};
    static SDL_FRect sideGrayRight = {scaledSize.w - border - 1, 1 + border, border, scaledSize.h - 2 * border - 2};
    static SDL_FRect innerBorder = {border + 1, border + 1, scaledSize.w - 2 * border - 2, scaledSize.h - 2 * border - 2};

    state.sdl.drawColor(Black);
    state.sdl.rect(outerBorder);

    state.sdl.drawColor(Gray);

    state.sdl.rect(topGray);
    state.sdl.rect(bottomGray);
    state.sdl.rect(sideGrayLeft);
    state.sdl.rect(sideGrayRight);

    state.sdl.drawColor(Black);
    state.sdl.rect(innerBorder);

    float tickPosition = 1 + border + state.buttonSize;

    // horizontal ticks
    state.sdl.line(1, tickPosition, border, tickPosition);                                       // top left
    state.sdl.line(scaledSize.w - border - 1, tickPosition, scaledSize.w - 2, tickPosition);     // top right
    state.sdl.line(1, scaledSize.h - 2 - tickPosition, border, scaledSize.h - 2 - tickPosition); // bottom left
    state.sdl.line(scaledSize.w - border - 1, scaledSize.h - 2 - tickPosition,
                   scaledSize.w - 2, scaledSize.h - 2 - tickPosition); // bottom right

    // verticalTicks
    state.sdl.line(tickPosition, 1, tickPosition, border);                                   // top left
    state.sdl.line(tickPosition, scaledSize.h - border - 1, tickPosition, scaledSize.h - 2); // bottom left

    state.sdl.line(scaledSize.w - 2 - tickPosition, 1, scaledSize.w - 2 - tickPosition, border); // top right
    state.sdl.line(scaledSize.w - 2 - tickPosition, scaledSize.h - border - 1,
                   scaledSize.w - 2 - tickPosition, scaledSize.h - 2); // bottom right

    state.sdl.drawColor(Magenta);
    state.sdl.present();
}