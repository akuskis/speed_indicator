#include "math.hpp"

#include <cmath>


namespace s_indicator::math
{
double toRad(double angle)
{
    return angle * M_PI / 180.0;
}
} // namespace s_indicator::math
