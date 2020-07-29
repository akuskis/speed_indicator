#include "Texture.hpp"


namespace s_indicator
{
Texture::Texture()
    : texture_(nullptr, SDL_DestroyTexture)
{
}

SDL_Texture* Texture::texture() const
{
    return texture_.get();
}

void Texture::setTexture(SDL_Texture* value)
{
    texture_.reset(value);
}

SDL_Rect const& Texture::rect() const
{
    return rect_;
}

void Texture::setRect(SDL_Rect const& value)
{
    rect_ = value;
}

} // namespace s_indicator
