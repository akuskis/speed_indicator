#pragma once

#include <cstdint>


namespace s_indicator
{
struct Configuration
{
    [[nodiscard]] uint32_t getFrameRate() const;

    [[nodiscard]] int getScreenWidth() const;
    [[nodiscard]] int getScreenHeight() const;
};

} // namespace s_indicator
