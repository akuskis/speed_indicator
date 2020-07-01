#include "Configuration.hpp"
#include "Logger.hpp"
#include "engine/Engine.hpp"


int SDL_main(int /* argc */, char** /* argv */)
{
    try
    {
        s_indicator::Configuration cfg;
        s_indicator::Engine engine(cfg);
        engine.runLoop();
    }
    catch (std::runtime_error const& error)
    {
        s_indicator::Logger::error("Critical error: %s", error.what());
    }

    return EXIT_SUCCESS;
}
