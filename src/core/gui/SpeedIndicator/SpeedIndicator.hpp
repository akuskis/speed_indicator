#pragma once

#include "gui/GraphicsObject.hpp"


namespace s_indicator
{
class SpeedIndicator : public GraphicsObject
{
public:
    SpeedIndicator();
    virtual ~SpeedIndicator();

    void setSize(Size const& value) override;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};
} // namespace s_indicator
