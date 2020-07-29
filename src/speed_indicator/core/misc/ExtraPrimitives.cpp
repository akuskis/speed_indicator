// Extracted some code from https://github.com/rtrussell/BBCSDL
// To get more functionality of SDL_gfx

#include "ExtraPrimitives.hpp"

#include "SDL2_gfxPrimitives.h"


namespace
{
int renderdrawline(SDL_Renderer* renderer, int x1, int y1, int x2, int y2)
{
    int result;
    if ((x1 == x2) && (y1 == y2))
        result = SDL_RenderDrawPoint(renderer, x1, y1);
    else if ((y1 == y2) && (x1 != x2))
    {
        int x;
        if (x1 > x2)
        {
            x = x1;
            x1 = x2;
            x2 = x;
        }
        auto* points = (SDL_Point*)malloc((x2 - x1 + 1) * sizeof(SDL_Point));
        if (points == NULL)
            return -1;
        for (x = x1; x <= x2; x++)
        {
            points[x - x1].x = x;
            points[x - x1].y = y1;
        }
        result = SDL_RenderDrawPoints(renderer, points, x2 - x1 + 1);
        free(points);
    }
    else if ((x1 == x2) && (y1 != y2))
    {
        int y;
        if (y1 > y2)
        {
            y = y1;
            y1 = y2;
            y2 = y;
        }
        auto* points = (SDL_Point*)malloc((y2 - y1 + 1) * sizeof(SDL_Point));
        if (points == NULL)
            return -1;
        for (y = y1; y <= y2; y++)
        {
            points[y - y1].x = x1;
            points[y - y1].y = y;
        }
        result = SDL_RenderDrawPoints(renderer, points, y2 - y1 + 1);
        free(points);
    }
    else
        result = SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
    return result;
}

int hlinecliparc(SDL_Renderer* renderer, int x1, int x2, int y, int xc, int yc, double s, double f)
{
    int result = 0;
    double a1, a2;
    a1 = atan2(y, x1);
    a2 = atan2(y, x2);
    if (a1 > a2)
    {
        double a = a1;
        a1 = a2;
        a2 = a;
        int x = x1;
        x1 = x2;
        x2 = x;
    }
    if (f < s)
    {
        if ((a1 > f) && (a2 < s))
            return result;
        if ((a1 < s) && (a1 > f))
            x1 = y / tan(s);
        if ((a2 > f) && (a2 < s))
            x2 = y / tan(f);
        if ((a1 < f) && (a2 > s))
        {
            result |= renderdrawline(renderer, x1 + xc, y + yc, y / tan(f) + xc, y + yc);
            result |= renderdrawline(renderer, y / tan(s) + xc, y + yc, x2 + xc, y + yc);
            return result;
        }
    }
    else
    {
        if ((a1 > f) || (a2 < s))
            return result;
        if (a1 < s)
            x1 = y / tan(s);
        if (a2 > f)
            x2 = y / tan(f);
    }
    result |= renderdrawline(renderer, x1 + xc, y + yc, x2 + xc, y + yc);
    return result;
}

} // namespace


namespace gfx
{
int thickArcRGBA(SDL_Renderer* renderer, Sint16 xc, Sint16 yc, Sint16 rad, Sint16 start, Sint16 end, Uint8 r, Uint8 g,
                 Uint8 b, Uint8 a, Uint8 thick)
{
    int result = 0;
    int ri, ro, x, y, z;
    double ri2, ro2, s, f;

    if (thick <= 1)
        return arcRGBA(renderer, xc, yc, rad, start, end, r, g, b, a);

    while (start < -180)
        start += 360;
    while (start >= 180)
        start -= 360;
    while (end < -180)
        end += 360;
    while (end >= 180)
        end -= 360;
    s = M_PI * (double)start / 180.0;
    f = M_PI * (double)end / 180.0;
    if (start == end)
        return 0;

    ri = rad - thick / 2;
    ro = ri + thick - 1;
    if (ri <= 0)
        return -1;

    ri2 = ri * ri;
    ro2 = ro * ro;

    result |= SDL_SetRenderDrawBlendMode(renderer, (a == 255) ? SDL_BLENDMODE_NONE : SDL_BLENDMODE_BLEND);
    result |= SDL_SetRenderDrawColor(renderer, r, g, b, a);

    for (y = -ro; y <= -ri; y++)
    {
        x = sqrt(ro2 * (1.0 - y * y / ro2)) + 0.5;
        result |= hlinecliparc(renderer, -x, x, y, xc, yc, s, f);
    }
    for (y = -ri + 1; y <= ri - 1; y++)
    {
        x = sqrt(ro2 * (1.0 - y * y / ro2)) + 0.5;
        z = sqrt(ri2 * (1.0 - y * y / ri2)) + 0.5;
        result |= hlinecliparc(renderer, z, x, y, xc, yc, s, f);
        result |= hlinecliparc(renderer, -z, -x, y, xc, yc, s, f);
    }
    for (y = ro; y >= ri; y--)
    {
        x = sqrt(ro2 * (1.0 - y * y / ro2)) + 0.5;
        result |= hlinecliparc(renderer, -x, x, y, xc, yc, s, f);
    }
    return result;
}

int thickArcColor(SDL_Renderer* renderer, Sint16 x, Sint16 y, Sint16 rad, Sint16 start, Sint16 end, Uint32 color,
                  Uint8 thick)
{
    Uint8* c = (Uint8*)&color;
    return thickArcRGBA(renderer, x, y, rad, start, end, c[0], c[1], c[2], c[3], thick);
}

} // namespace gfx