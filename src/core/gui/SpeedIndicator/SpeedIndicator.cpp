#include "SpeedIndicator.hpp"

#include "BasePlate.hpp"


namespace s_indicator
{
struct SpeedIndicator::Impl
{
    BasePlate* base_plate;
};

SpeedIndicator::SpeedIndicator()
    : impl(std::make_unique<Impl>())
{
    impl->base_plate = new BasePlate();
    addChild(impl->base_plate);
}

SpeedIndicator::~SpeedIndicator() = default;

void SpeedIndicator::setSize(Size const& value)
{
    impl->base_plate->setSize(value);

    GraphicsObject::setSize(value);
}

} // namespace s_indicator
