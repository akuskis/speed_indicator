#pragma once

#include <android/log.h>

#include <string>


namespace s_indicator
{
namespace Logger
{
namespace details
{
template <typename... Args>
void show(int level, std::string msg, Args... args)
{
    msg.push_back('\n');

    if constexpr (sizeof...(Args))
        __android_log_print(level, "Speed Indicator", msg.c_str(), args...);
    else
        __android_log_write(level, "Speed Indicator", msg.c_str());
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
} // namespace s_indicator
