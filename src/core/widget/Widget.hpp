#pragma once

#include "gui/GraphicsObject.hpp"


namespace s_indicator
{
class Widget : public GraphicsObject
{
public:
    Widget(Point const& pos = {}, Size const& size = {});
    virtual ~Widget();

    void render(SDL_Renderer* renderer) override;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};

} // namespace s_indicator
