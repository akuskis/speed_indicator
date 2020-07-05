#pragma once

#include "gui/GraphicsObject.hpp"


namespace s_indicator
{
class BasePlate : public GraphicsObject
{
public:
    void render(SDL_Renderer* renderer) override;
};
} // namespace s_indicator
