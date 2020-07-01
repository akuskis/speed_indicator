#pragma once

#include <stdexcept>


namespace s_indicator
{
template <typename C, typename D>
class ObjectRaii
{
public:
    template <typename... Args>
    ObjectRaii(C c, D d, char const* error_message_, Args... args)
        : deleter_(d)
    {
        if (c(args...) != 0)
            throw std::runtime_error(error_message_);
    }

    ~ObjectRaii()
    {
        deleter_();
    }

private:
    D deleter_;
};

} // namespace s_indicator
