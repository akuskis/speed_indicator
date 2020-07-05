#pragma once

#include <cstddef>
#include <memory>

#include <SDL_ttf.h>


namespace s_indicator
{
class Font
{
public:
    enum Type { roboto, roboto_bold, icons };

    static TTF_Font* get(Font::Type type, size_t pt_size);

private:
    Font();
    ~Font() = default;

    static Font const& instance();

    struct Impl;
    std::unique_ptr<Impl> impl;
};

} // namespace s_indicator
