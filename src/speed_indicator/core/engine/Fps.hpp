#pragma once

#include <cstdint>


namespace s_indicator
{
class Fps
{
public:
    explicit Fps(uint16_t frame_rate);

    void next();

private:
    uint16_t const ticks_per_frame_;
    uint32_t next_time_;
};

} // namespace s_indicator
