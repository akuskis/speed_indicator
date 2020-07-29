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

    if (now > next_time_) {
        next_time_ = now;
    }

    // NOTE: take into account accuracy of SDL_Delay
    // If you want some better FPS, remove SDL_Delay or use better clock
    SDL_Delay(next_time_ - now);
    next_time_ += ticks_per_frame_;
}

} // namespace s_indicator
