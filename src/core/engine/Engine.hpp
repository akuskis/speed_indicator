#pragma once

#include <SDL.h>

#include <memory>


namespace s_indicator
{
struct Configuration;

class Engine
{
public:
    explicit Engine(Configuration& cfg);
    ~Engine();

    void runLoop();
    void stop();

private:
    struct Impl;
    std::unique_ptr<Impl> impl;

    void update();
    void render();
};

} // namespace s_indicator
