#include "BasePlate.hpp"

#include "misc/ExtraPrimitives.hpp"

#include "SDL2_gfxPrimitives.h"


namespace
{
uint32_t const BACKGROUND_COLOR = 0xffe3e3e3;
uint32_t const LINE_COLOR = 0xffe8ba00;

int const START_ANGLE = 120;
int const END_ANGLE = 420;
constexpr int TOTAL_ANGLE = END_ANGLE - START_ANGLE;

int const MAX_SPEED = 220;
int const MAJOR_SPEED_TICK = 20;
int const MINOR_SPEED_TICK = 10;

double toRad(double angle)
{
    return angle * M_PI / 180.0;
}

bool isMajorTick(int speed)
{
    return speed % MAJOR_SPEED_TICK == 0;
}
} // namespace


namespace s_indicator
{
void BasePlate::render(SDL_Renderer* renderer)
{
    int const w = getSize().width();
    int const h = getSize().height();
    int const radius = std::min(w, h) / 2;

    int const x = w / 2;
    int const y = h / 2;

    auto const circle_radius = radius * 0.7;
    auto const major_tick_radius = radius * 0.6;
    auto const minor_tick_radius = radius * 0.65;

    float const angles_per_unit = TOTAL_ANGLE / static_cast<float>(MAX_SPEED);

    filledCircleColor(renderer, x, y, radius, LINE_COLOR);
    filledCircleColor(renderer, x, y, radius * 0.95, BACKGROUND_COLOR);
    gfx::thickArcColor(renderer, x, y, circle_radius, START_ANGLE, END_ANGLE, LINE_COLOR, 3);

    for (int speed = 0; speed <= MAX_SPEED; speed += MINOR_SPEED_TICK)
    {
        auto const angle_delta = START_ANGLE + angles_per_unit * static_cast<double>(speed);
        auto const x_1 = cos(toRad(angle_delta)) * circle_radius;
        auto const y_1 = sin(toRad(angle_delta)) * circle_radius;

        if (isMajorTick(speed))
        {
            auto const x_2 = cos(toRad(angle_delta)) * major_tick_radius;
            auto const y_2 = sin(toRad(angle_delta)) * major_tick_radius;

            thickLineColor(renderer, x + x_1, y + y_1, x + x_2, y + y_2, 6, LINE_COLOR);
        }
        else
        {
            auto const x_2 = cos(toRad(angle_delta)) * minor_tick_radius;
            auto const y_2 = sin(toRad(angle_delta)) * minor_tick_radius;

            thickLineColor(renderer, x + x_1, y + y_1, x + x_2, y + y_2, 6, LINE_COLOR);
        }
    }

    GraphicsObject::render(renderer);
}

} // namespace s_indicator
