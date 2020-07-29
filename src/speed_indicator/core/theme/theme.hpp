#pragma once

#include "Font.hpp"

#include <string_view>


class Texture;


namespace s_indicator::theme
{
void getTextTexture(SDL_Renderer* renderer, Texture* texture, int x, int y, std::string_view text, Font::Type font_type,
                    size_t pt_size, SDL_Color const& color);

} // namespace s_indicator::theme
