#include "Configuration.hpp"


namespace
{
uint32_t const DEFAULT_FRAME_RATE = 60;

int const DEFAULT_SCREEN_WIDTH = 1200;
int const DEFAULT_SCREEN_HEIGHT = 900;
} // namespace


namespace s_indicator
{
uint32_t Configuration::getFrameRate() const
{
    return DEFAULT_FRAME_RATE;
}

int Configuration::getScreenWidth() const
{
    return DEFAULT_SCREEN_WIDTH;
}

int Configuration::getScreenHeight() const
{
    return DEFAULT_SCREEN_HEIGHT;
}

} // namespace s_indicator
