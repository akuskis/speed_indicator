#include "Logger.hpp"

#include <SDL.h>


int SDL_main(int /* argc */, char** /* argv */)
{
    using namespace s_indicator::core;

    if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
        Logger::error("SDL_Init: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_Window* window = SDL_CreateWindow("Speed Indicator", 0, 0, 640, 480, SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN);
    if (window == nullptr)
    {
        Logger::error("SDL_CreateWindow: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr)
    {
        Logger::error("SDL_CreateRenderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        return EXIT_FAILURE;
    }

    Logger::info("SDL was loaded successfully\n");

    bool done = false;
    while (!done)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            done = (event.type == SDL_QUIT || event.type == SDL_KEYDOWN || event.type == SDL_FINGERDOWN);
        }

        SDL_SetRenderDrawColor(renderer, 0xAA, 0x00, 0xA0, 0xFF);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}
