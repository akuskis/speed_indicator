#pragma once

#include <gui/GraphicsObject.hpp>


namespace s_indicator
{
class Arrow : public GraphicsObject
{
public:
    explicit Arrow(double angle);

    void setAngle(double value);

    void render(SDL_Renderer* renderer) override;

private:
    double angle_ = 0;
};

} // namespace s_indicator
