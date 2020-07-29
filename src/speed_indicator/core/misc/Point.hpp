#pragma once


namespace s_indicator
{
class Point
{
public:
    Point() = default;
    Point(int x, int y);

    [[nodiscard]] int x() const;
    [[nodiscard]] int y() const;

    [[nodiscard]] bool operator==(Point const& rhs) const;
    [[nodiscard]] bool operator!=(Point const& rhs) const;

    Point& operator*=(int factor);
    Point& operator*=(Point const& rhs);

    Point& operator+=(int factor);
    Point& operator+=(Point const& rhs);

    Point& operator-=(int factor);
    Point& operator-=(Point const& rhs);

private:
    int x_ = 0, y_ = 0;
};

[[nodiscard]] inline Point operator*(Point const& point, int factor)
{
    return Point(point.x() * factor, point.y() * factor);
}

[[nodiscard]] inline Point operator*(int factor, Point const& point)
{
    return point * factor;
}

[[nodiscard]] inline Point operator*(Point const& lhs, Point const& rhs)
{
    return Point(lhs.x() * rhs.x(), lhs.y() * rhs.y());
}

[[nodiscard]] inline Point operator+(Point const& point, int factor)
{
    return Point(point.x() + factor, point.y() + factor);
}

[[nodiscard]] inline Point operator+(int factor, Point const& point)
{
    return point + factor;
}

[[nodiscard]] inline Point operator+(Point const& lhs, Point const& rhs)
{
    return Point(lhs.x() + rhs.x(), lhs.y() + rhs.y());
}

[[nodiscard]] inline Point operator-(Point const& point, int factor)
{
    return Point(point.x() - factor, point.y() - factor);
}

[[nodiscard]] inline Point operator-(int factor, Point const& point)
{
    return Point(factor - point.x(), factor - point.y());
}

[[nodiscard]] inline Point operator-(Point const& lhs, Point const& rhs)
{
    return Point(lhs.x() - rhs.x(), lhs.y() - rhs.y());
}

} // namespace s_indicator
