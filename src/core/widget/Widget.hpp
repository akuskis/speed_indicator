#pragma once

#include "gui/GraphicsObject.hpp"


namespace s_indicator
{
class Widget : public GraphicsObject
{
public:
    Widget(Point const& pos = {}, Size const& size = {});
    virtual ~Widget() = default;

    void render(SDL_Renderer* renderer) override;
};

} // namespace s_indicator
