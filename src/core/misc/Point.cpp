#include "Point.hpp"


namespace s_indicator
{
Point::Point(int const x, int const y)
    : x_(x)
    , y_(y)
{
}

int Point::x() const
{
    return x_;
}

int Point::y() const
{
    return y_;
}

bool Point::operator==(Point const& rhs) const
{
    return x_ == rhs.x_ && y_ == rhs.y_;
}

bool Point::operator!=(Point const& rhs) const
{
    return !(*this == rhs);
}


Point& Point::operator*=(int const factor)
{
    x_ *= factor;
    y_ *= factor;

    return *this;
}

Point& Point::operator*=(Point const& rhs)
{
    x_ *= rhs.x();
    y_ *= rhs.y();

    return *this;
}

Point& Point::operator+=(int const factor)
{
    x_ += factor;
    y_ += factor;

    return *this;
}

Point& Point::operator+=(Point const& rhs)
{
    x_ += rhs.x();
    y_ += rhs.y();

    return *this;
}

Point& Point::operator-=(int const factor)
{
    x_ -= factor;
    y_ -= factor;

    return *this;
}

Point& Point::operator-=(Point const& rhs)
{
    x_ -= rhs.x();
    y_ -= rhs.y();

    return *this;
}

} // namespace s_indicator
