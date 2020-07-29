#pragma once


namespace s_indicator
{
class Size
{
public:
    Size() = default;
    Size(int w, int h);

    [[nodiscard]] int width() const;
    [[nodiscard]] int height() const;

    [[nodiscard]] bool operator==(Size const& rhs) const;
    [[nodiscard]] bool operator!=(Size const& rhs) const;

    Size& operator*=(int factor);
    Size& operator*=(Size const& rhs);

    Size& operator+=(int factor);
    Size& operator+=(Size const& rhs);

    Size& operator-=(int factor);
    Size& operator-=(Size const& rhs);

private:
    int w_ = 0, h_ = 0;
};


[[nodiscard]] inline Size operator*(Size const& size, int factor)
{
    return Size(size.width() * factor, size.height() * factor);
}

[[nodiscard]] inline Size operator*(int factor, Size const& size)
{
    return size * factor;
}

[[nodiscard]] inline Size operator*(Size const& lhs, Size const& rhs)
{
    return Size(lhs.width() * rhs.width(), lhs.height() * rhs.height());
}

[[nodiscard]] inline Size operator+(Size const& size, int factor)
{
    return Size(size.width() + factor, size.height() + factor);
}

[[nodiscard]] inline Size operator+(int factor, Size const& size)
{
    return size + factor;
}

[[nodiscard]] inline Size operator+(Size const& lhs, Size const& rhs)
{
    return Size(lhs.width() + rhs.width(), lhs.height() + rhs.height());
}

[[nodiscard]] inline Size operator-(Size const& size, int factor)
{
    return Size(size.width() - factor, size.height() - factor);
}

[[nodiscard]] inline Size operator-(int factor, Size const& size)
{
    return Size(factor - size.width(), factor - size.height());
}

[[nodiscard]] inline Size operator-(Size const& lhs, Size const& rhs)
{
    return Size(lhs.width() - rhs.width(), lhs.height() - rhs.height());
}
} // namespace s_indicator
