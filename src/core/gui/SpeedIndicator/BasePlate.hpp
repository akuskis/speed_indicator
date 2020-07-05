#pragma once

#include "gui/GraphicsObject.hpp"


namespace s_indicator
{
class BasePlate : public GraphicsObject
{
public:
    BasePlate(int const start_angle, int const end_angle, int const max_speed);

    void render(SDL_Renderer* renderer) override;

private:
    int const start_angle_, end_angle_, max_speed_;
};
} // namespace s_indicator
