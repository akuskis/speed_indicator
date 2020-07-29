#include "Arrow.hpp"

#include "misc/math.hpp"

#include <SDL2_gfxPrimitives.h>


namespace
{
uint32_t const LINE_COLOR = 0xff005cbf;
uint32_t const BASE_COLOR = 0xffe3e3e3;

} // namespace

namespace s_indicator
{
Arrow::Arrow(double angle)
    : angle_(angle)
{
}

void Arrow::setAngle(double value)
{
    angle_ = value;
}

void Arrow::render(SDL_Renderer* renderer)
{
    int const w = getSize().width();
    int const h = getSize().height();
    int const radius = std::min(w, h) / 2;

    int const x = w / 2;
    int const y = h / 2;

    { // draw base of arrow
        filledCircleColor(renderer, x, y, radius * 0.07, LINE_COLOR);
        filledCircleColor(renderer, x, y, radius * 0.05, BASE_COLOR);
    }

    { // draw arrow
        auto const long_radius = radius * 0.75;
        auto const short_radius = radius * 0.15;

        auto const x_1 = cos(math::toRad(angle_)) * long_radius;
        auto const y_1 = sin(math::toRad(angle_)) * long_radius;
        auto const x_2 = cos(math::toRad(angle_ + 180)) * short_radius;
        auto const y_2 = sin(math::toRad(angle_ + 180)) * short_radius;

        thickLineColor(renderer, x + x_1, y + y_1, x + x_2, y + y_2, 6, LINE_COLOR);
    }

    GraphicsObject::render(renderer);
}

} // namespace s_indicator
