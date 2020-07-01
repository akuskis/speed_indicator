#include "Engine.hpp"

#include "Configuration.hpp"
#include "Fps.hpp"
#include "misc/ObjectRaii.hpp"

#include <string>


namespace
{
int const FIRST_SUPPORTED_RENDERER = -1;
} // namespace


namespace s_indicator
{
struct Engine::Impl
{
    Configuration& cfg;
    ObjectRaii<int (*)(uint32_t), void (*)()> sdl;
    std::unique_ptr<SDL_Window, void (*)(SDL_Window*)> window;
    std::unique_ptr<SDL_Renderer, void (*)(SDL_Renderer*)> renderer;
    bool running = false;

    explicit Impl(Configuration& cfg)
        : cfg(cfg)
        , sdl{SDL_Init, SDL_Quit, "Can't initialize SDL (SDL_Init)", SDL_INIT_EVERYTHING}
        , window{nullptr, SDL_DestroyWindow}
        , renderer{nullptr, SDL_DestroyRenderer}
    {
    }
};

Engine::Engine(Configuration& cfg)
    : impl(std::make_unique<Impl>(cfg))
{
    impl->window.reset(SDL_CreateWindow("Speed Indicator",
                                        0,
                                        0,
                                        cfg.getScreenWidth(),
                                        cfg.getScreenHeight(),
                                        SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN));
    if (!impl->window)
        throw std::runtime_error(std::string("SDL_CreateWindow: ") + SDL_GetError());

    impl->renderer.reset(SDL_CreateRenderer(impl->window.get(), FIRST_SUPPORTED_RENDERER, SDL_RENDERER_ACCELERATED));
    if (!impl->renderer)
        throw std::runtime_error(std::string("SDL_CreateRenderer: ") + SDL_GetError());

    impl->running = true;
}

Engine::~Engine() = default;

void Engine::runLoop()
{
    Fps fps(impl->cfg.getFrameRate());

    while (impl->running)
    {
        render();
        fps.next();
    }
}

void Engine::stop()
{
    impl->running = false;
}

void Engine::render()
{
    SDL_SetRenderDrawColor(impl->renderer.get(), 0xAA, 0x00, 0xA0, 0xFF);
    SDL_RenderClear(impl->renderer.get());
    SDL_RenderPresent(impl->renderer.get());
}

} // namespace s_indicator
