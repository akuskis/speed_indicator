#include <SDL.h>
#include <android/log.h>


namespace
{
char const* const APPNAME = "Throttle_SDL";
} // namespace


int SDL_main(int /* argc */, char** /* argv */)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
        __android_log_print(ANDROID_LOG_VERBOSE, APPNAME, "SDL_Init: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_Window* window = SDL_CreateWindow("Hello World!", 0, 0, 640, 480, SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN);
    if (window == nullptr)
    {
        __android_log_print(ANDROID_LOG_ERROR, APPNAME, "SDL_CreateWindow: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr)
    {
        __android_log_print(ANDROID_LOG_ERROR, APPNAME, "SDL_CreateRenderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        return EXIT_FAILURE;
    }

    __android_log_print(ANDROID_LOG_INFO, APPNAME, "SDL_Success: %s\n", SDL_GetError());

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
