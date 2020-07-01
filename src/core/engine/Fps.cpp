#include "Fps.hpp"

#include <SDL_timer.h>

#include <cmath>


namespace s_indicator
{
Fps::Fps(uint16_t const frame_rate)
    : ticks_per_frame_(std::floor(1000. / frame_rate))
    , next_time_(SDL_GetTicks() + ticks_per_frame_)
{
}

void Fps::next()
{
    auto const now = SDL_GetTicks();

    if (now > next_time_)
        next_time_ = now;

    SDL_Delay(next_time_ - now);
    next_time_ += ticks_per_frame_;
}

} // namespace s_indicator
