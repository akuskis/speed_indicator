#include "BasePlate.hpp"

#include "misc/ExtraPrimitives.hpp"
#include "misc/math.hpp"
#include "theme/theme.hpp"

#include "SDL2_gfxPrimitives.h"

#include <string>


namespace
{
uint32_t const BACKGROUND_COLOR = 0xffe3e3e3;
uint32_t const LINE_COLOR = 0xffe8ba00;

int const LABEL_OFFSET = 15;
int const LABEL_SIZE = 40;
SDL_Color const LABEL_COLOR{200, 0, 200, 255};

int const MAJOR_SPEED_TICK = 20;
int const MINOR_SPEED_TICK = 10;

bool isMajorTick(int speed)
{
    return speed % MAJOR_SPEED_TICK == 0;
}
} // namespace


namespace s_indicator
{
BasePlate::BasePlate(int const start_angle, int const end_angle, int const max_speed)
    : start_angle_(start_angle)
    , end_angle_(end_angle)
    , max_speed_(max_speed)
{
}

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

    auto const angle_range = end_angle_ - start_angle_;
    float const angles_per_unit = angle_range / static_cast<float>(max_speed_);

    filledCircleColor(renderer, x, y, radius, LINE_COLOR);
    filledCircleColor(renderer, x, y, radius * 0.95, BACKGROUND_COLOR);
    gfx::thickArcColor(renderer, x, y, circle_radius, start_angle_, end_angle_, LINE_COLOR, 3);

    updateLabelTextures(renderer);

    for (int speed = 0; speed <= max_speed_; speed += MINOR_SPEED_TICK)
    {
        auto const angle_delta = start_angle_ + angles_per_unit * static_cast<double>(speed);
        auto const x_1 = cos(math::toRad(angle_delta)) * circle_radius;
        auto const y_1 = sin(math::toRad(angle_delta)) * circle_radius;

        if (isMajorTick(speed))
        {
            auto const x_2 = cos(math::toRad(angle_delta)) * major_tick_radius;
            auto const y_2 = sin(math::toRad(angle_delta)) * major_tick_radius;

            thickLineColor(renderer, x + x_1, y + y_1, x + x_2, y + y_2, 6, LINE_COLOR);

            // draw label
            auto const* texture = numeric_labels_.at(speed).get();
            auto const half_of_w = texture->rect().w / 2.;
            auto const half_of_h = texture->rect().h / 2.;
            auto const label_x = cos(math::toRad(angle_delta)) * (circle_radius + LABEL_OFFSET + half_of_w);
            auto const label_y = sin(math::toRad(angle_delta)) * (circle_radius + LABEL_OFFSET + half_of_h);

            SDL_Rect label_rect{static_cast<int>(x + label_x - half_of_w),
                                static_cast<int>(y + label_y - half_of_h),
                                texture->rect().w,
                                texture->rect().h};
            SDL_RenderCopy(renderer, texture->texture(), nullptr, &label_rect);
        }
        else
        {
            auto const x_2 = cos(math::toRad(angle_delta)) * minor_tick_radius;
            auto const y_2 = sin(math::toRad(angle_delta)) * minor_tick_radius;

            thickLineColor(renderer, x + x_1, y + y_1, x + x_2, y + y_2, 6, LINE_COLOR);
        }
    }

    GraphicsObject::render(renderer);
}

void BasePlate::updateLabelTextures(SDL_Renderer* renderer)
{
    if (numeric_labels_.empty())
    {
        for (int speed = 0; speed <= max_speed_; speed += MAJOR_SPEED_TICK)
        {
            auto texture = std::make_unique<Texture>();

            theme::getTextTexture(
                renderer, texture.get(), 0, 0, std::to_string(speed), Font::Type::roboto_bold, LABEL_SIZE, LABEL_COLOR);

            numeric_labels_.insert({speed, std::move(texture)});
        }
    }
}

} // namespace s_indicator
