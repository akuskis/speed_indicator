#pragma once

#include <android/log.h>


namespace s_indicator::core
{
namespace Logger
{
namespace details
{
template <typename... Args>
void show(int level, char const* msg, Args... args)
{
    if constexpr (sizeof...(Args))
        __android_log_print(level, "Speed Indicator", msg, args...);
    else
        __android_log_write(level, "Speed Indicator", msg);
}
} // namespace details


template <typename... Args>
void info(Args... args)
{
    details::show(ANDROID_LOG_INFO, args...);
}

template <typename... Args>
void error(Args... args)
{
    details::show(ANDROID_LOG_INFO, args...);
}

} // namespace Logger
} // namespace s_indicator::core
