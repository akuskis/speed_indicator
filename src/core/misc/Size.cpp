#include "Size.hpp"


namespace s_indicator
{
Size::Size(int w, int h)
    : w_(w)
    , h_(h)
{
}

int Size::width() const
{
    return w_;
}

int Size::height() const
{
    return h_;
}

bool Size::operator==(Size const& rhs) const
{
    return w_ == rhs.w_ && h_ == rhs.h_;
}

bool Size::operator!=(Size const& rhs) const
{
    return !(*this == rhs);
}


Size& Size::operator*=(int const factor)
{
    w_ *= factor;
    h_ *= factor;

    return *this;
}

Size& Size::operator*=(Size const& rhs)
{
    w_ *= rhs.width();
    h_ *= rhs.height();

    return *this;
}

Size& Size::operator+=(int const factor)
{
    w_ += factor;
    h_ += factor;

    return *this;
}

Size& Size::operator+=(Size const& rhs)
{
    w_ += rhs.width();
    h_ += rhs.height();

    return *this;
}

Size& Size::operator-=(int const factor)
{
    w_ -= factor;
    h_ -= factor;

    return *this;
}

Size& Size::operator-=(Size const& rhs)
{
    w_ -= rhs.width();
    h_ -= rhs.height();

    return *this;
}
} // namespace s_indicator
