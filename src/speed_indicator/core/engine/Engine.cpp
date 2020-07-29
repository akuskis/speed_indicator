#include "Engine.hpp"

#include "Configuration.hpp"
#include "Fps.hpp"
#include "misc/ObjectRaii.hpp"
#include "widget/Widget.hpp"

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

    std::unique_ptr<Widget> wgt = nullptr;

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

    int window_width, window_height;
    SDL_GetWindowSize(impl->window.get(), &window_width, &window_height);
    impl->wgt = std::make_unique<Widget>(Point{}, Size{window_width, window_height});

    impl->running = true;
}

Engine::~Engine() = default;

void Engine::runLoop()
{
    Fps fps(impl->cfg.getFrameRate());

    while (impl->running)
    {
        update();
        render();
        fps.next();
    }
}

void Engine::stop()
{
    impl->running = false;
}

void Engine::update()
{
    impl->wgt->update();
}

void Engine::render()
{
    SDL_Renderer* renderer = impl->renderer.get();

    SDL_SetRenderDrawColor(impl->renderer.get(), 0xFF, 0x00, 0x00, 0xFF);
    SDL_RenderClear(renderer);

    impl->wgt->render(renderer);

    SDL_RenderPresent(renderer);
}

} // namespace s_indicator
