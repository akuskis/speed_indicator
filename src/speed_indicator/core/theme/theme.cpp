#include "theme.hpp"

#include "misc/Texture.hpp"


namespace s_indicator::theme
{
void getTextTexture(SDL_Renderer* renderer, Texture* texture, int x, int y, std::string_view text, Font::Type font_type,
                    size_t pt_size, SDL_Color const& color)
{
    TTF_Font* font = Font::get(font_type, pt_size);
    if (!font)
        return;

    SDL_Surface* surface = TTF_RenderUTF8_Blended(font, text.data(), color);
    if (!surface)
    {
        texture->setTexture(nullptr);
        texture->setRect(SDL_Rect{x, y, 0, 0});
        return;
    }

    texture->setTexture(SDL_CreateTextureFromSurface(renderer, surface));
    texture->setRect(SDL_Rect{x, y, surface->w, surface->h});
    SDL_FreeSurface(surface);
}
} // namespace s_indicator::theme
