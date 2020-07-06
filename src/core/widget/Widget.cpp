#include "Widget.hpp"

#include "gui/SpeedIndicator/SpeedIndicator.hpp"


namespace s_indicator
{
struct Widget::Impl
{
    SpeedIndicator* speed_indicator = nullptr;
};

Widget::Widget(Point const& pos, Size const& size)
    : GraphicsObject(pos, size)
    , impl(std::make_unique<Impl>())
{
    impl->speed_indicator = new SpeedIndicator();
    impl->speed_indicator->setSize(getSize());

    addChild(impl->speed_indicator);
}

Widget::~Widget() = default;

void Widget::render(SDL_Renderer* renderer)
{
    SDL_Rect widget_rect{getPos().x(), getPos().y(), getSize().width(), getSize().height()};

    SDL_SetRenderDrawColor(renderer, 0xaa, 0xaa, 0xaa, 0xff);
    SDL_RenderFillRect(renderer, &widget_rect);

    GraphicsObject::render(renderer);
}

} // namespace s_indicator
