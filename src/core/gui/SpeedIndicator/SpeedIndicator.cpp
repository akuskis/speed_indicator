#include "SpeedIndicator.hpp"

#include "Arrow.hpp"
#include "BasePlate.hpp"


namespace
{
int const START_ANGLE = 120;
int const END_ANGLE = 420;

int const MAX_SPEED = 220;

} // namespace


namespace s_indicator
{
struct SpeedIndicator::Impl
{
    BasePlate* base_plate = nullptr;
    Arrow* arrow = nullptr;
};

SpeedIndicator::SpeedIndicator()
    : impl(std::make_unique<Impl>())
{
    impl->base_plate = new BasePlate(START_ANGLE, END_ANGLE, MAX_SPEED);
    addChild(impl->base_plate);

    impl->arrow = new Arrow(START_ANGLE);
    addChild(impl->arrow);
}

SpeedIndicator::~SpeedIndicator() = default;

void SpeedIndicator::setSize(Size const& value)
{
    impl->base_plate->setSize(value);
    impl->arrow->setSize(value);

    GraphicsObject::setSize(value);
}

void SpeedIndicator::setSpeed(double speed)
{
    impl->arrow->setAngle(START_ANGLE + (speed * (END_ANGLE - START_ANGLE)) / MAX_SPEED);
}

} // namespace s_indicator
