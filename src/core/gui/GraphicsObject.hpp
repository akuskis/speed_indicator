#pragma once

#include "misc/Point.hpp"
#include "misc/Size.hpp"

#include <SDL.h>

#include <cstdint>
#include <vector>


namespace s_indicator
{
class GraphicsObject
{
public:
    explicit GraphicsObject(Point const& pos = {}, Size const& size = {});
    virtual ~GraphicsObject();

    virtual void render(SDL_Renderer* renderer);

    GraphicsObject* addChild(GraphicsObject* child);
    void clear();

    [[nodiscard]] Point const& getPos() const;
    void setPos(Point const& value);

    [[nodiscard]] Size getSize() const;
    void setSize(Size const& value);

private:
    Point pos_;
    Size size_;
    std::vector<GraphicsObject*> children_;
};

} // namespace s_indicator