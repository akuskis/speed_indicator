#include "Font.hpp"

#include "misc/ObjectRaii.hpp"
#include "resources/fonts/fonts.hpp"

#include <map>
#include <string>


namespace
{
SDL_RWops* createReader(s_indicator::Font::Type type)
{
    using namespace s_indicator;

    switch (type)
    {
    case Font::Type::roboto:
        return SDL_RWFromConstMem(fonts::roboto_regular_ttf, fonts::roboto_regular_ttf_size);
    case Font::Type::roboto_bold:
        return SDL_RWFromConstMem(fonts::roboto_bold_ttf, fonts::roboto_bold_ttf_size);
    case Font::Type::icons:
        return SDL_RWFromConstMem(fonts::entypo_ttf, fonts::entypo_ttf_size);
    }

    throw std::runtime_error("Not supported font type: " + std::to_string(type));
}
} // namespace


namespace s_indicator
{
struct Font::Impl
{
    ObjectRaii<int (*)(), void (*)()> ttf{TTF_Init, TTF_Quit, "Can't initialize TTF (TTF_Init)"};
    std::map<std::string, TTF_Font*> fonts;
    std::map<Font::Type, SDL_RWops*> fontReaders;

    SDL_RWops* getReader(Font::Type type)
    {
        auto iter = fontReaders.find(type);
        if (iter == fontReaders.end())
            iter = fontReaders.insert({type, createReader(type)}).first;

        return iter->second;
    }
};


Font::Font()
    : impl(std::make_unique<Impl>())
{
}

Font const& Font::instance()
{
    static Font font;
    return font;
}

TTF_Font* Font::get(Font::Type font_type, size_t pt_size)
{
    auto& impl = instance().impl;
    std::string font_name = std::to_string(font_type) + "_" + std::to_string(pt_size);

    auto iter = impl->fonts.find(font_name);
    if (iter == impl->fonts.end())
    {
        SDL_RWops* rw = impl->getReader(font_type);
        iter = impl->fonts.insert({font_name, TTF_OpenFontRW(rw, 0, pt_size)}).first;
    }

    return iter->second;
}

} // namespace s_indicator
