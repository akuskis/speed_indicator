#pragma once

#include "gui/GraphicsObject.hpp"
#include "misc/Texture.hpp"

#include <unordered_map>


namespace s_indicator
{
class BasePlate : public GraphicsObject
{
public:
    BasePlate(int const start_angle, int const end_angle, int const max_speed);

    void render(SDL_Renderer* renderer) override;

private:
    int const start_angle_, end_angle_, max_speed_;
    std::unordered_map<int, std::unique_ptr<Texture>> numeric_labels_;

    void updateLabelTextures(SDL_Renderer* renderer);
};
} // namespace s_indicator
