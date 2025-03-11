#include <SDL3/SDL.h>
#include <iostream>

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *win = SDL_CreateWindow("Win31", 1280, 1024, SDL_WINDOW_RESIZABLE);
    if (win == nullptr)
    {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(win, NULL);
    if (renderer == nullptr)
    {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }

    SDL_Event e;
    bool quit = false;

    // Define a rectangle
    SDL_FRect greenSquare{270, 190, 100, 100};

    while (!quit)
    {
        while (SDL_WaitEventTimeout(&e, 16))
        {
            std::cout << "event: " << e.type << std::endl;
            if (e.type == SDL_EVENT_QUIT)
            {
                quit = true;
            }
            else
            {
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Set render draw color to black
                SDL_RenderClear(renderer);                      // Clear the renderer

                SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Set render draw color to green
                SDL_RenderFillRect(renderer, &greenSquare);       // Render the rectangle

                SDL_RenderPresent(renderer); // Render the screen
            }
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}