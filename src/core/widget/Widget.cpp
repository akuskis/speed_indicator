#include "Widget.hpp"


namespace s_indicator
{
Widget::Widget(Point const& pos, Size const& size)
    : GraphicsObject(pos, size)
{
}

void Widget::render(SDL_Renderer* renderer)
{
    SDL_Rect widget_rect{getPos().x(), getPos().y(), getSize().width(), getSize().height()};

    SDL_SetRenderDrawColor(renderer, 0xaa, 0xaa, 0xaa, 0xff);
    SDL_RenderFillRect(renderer, &widget_rect);

    GraphicsObject::render(renderer);
}

} // namespace s_indicator
