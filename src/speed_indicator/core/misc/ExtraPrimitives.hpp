#include <SDL.h>

namespace gfx
{
int thickArcRGBA(SDL_Renderer* renderer, Sint16 xc, Sint16 yc, Sint16 rad, Sint16 start, Sint16 end, Uint8 r, Uint8 g,
                 Uint8 b, Uint8 a, Uint8 thick);

int thickArcColor(SDL_Renderer* renderer, Sint16 x, Sint16 y, Sint16 rad, Sint16 start, Sint16 end, Uint32 color,
                  Uint8 thick);

} // namespace gfx
