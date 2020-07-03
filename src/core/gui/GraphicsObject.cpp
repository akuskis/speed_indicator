#include "GraphicsObject.hpp"


namespace s_indicator
{
GraphicsObject::GraphicsObject(Point const& pos, Size const& size)
    : pos_(pos)
    , size_(size)
{
}

GraphicsObject::~GraphicsObject()
{
    clear();
}

void GraphicsObject::render(SDL_Renderer* renderer)
{
    for (auto* child : children_)
        child->render(renderer);
}

GraphicsObject* GraphicsObject::addChild(GraphicsObject* child)
{
    children_.push_back(child);
    return child;
}

void GraphicsObject::clear()
{
    for (auto* child : children_)
        delete child;

    children_.clear();
}

Point const& GraphicsObject::getPos() const
{
    return pos_;
}

void GraphicsObject::setPos(Point const& value)
{
    pos_ = value;
}

Size GraphicsObject::getSize() const
{
    return size_;
}

void GraphicsObject::setSize(Size const& value)
{
    size_ = value;
}

} // namespace s_indicator
