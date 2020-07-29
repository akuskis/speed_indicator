#pragma once

#include <SDL_rect.h>
#include <SDL_render.h>

#include <memory>


namespace s_indicator
{
class Texture
{
public:
    Texture();

    [[nodiscard]] SDL_Texture* texture() const;
    void setTexture(SDL_Texture* value);

    [[nodiscard]] SDL_Rect const& rect() const;
    void setRect(SDL_Rect const& value);

private:
    std::unique_ptr<SDL_Texture, void (*)(SDL_Texture*)> texture_;
    SDL_Rect rect_ = {0, 0, 0, 0};
};
} // namespace s_indicator
