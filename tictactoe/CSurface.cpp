#include "CSurface.h"

bool CSurface::Transparent(SDL_Surface *Surf_Dest, int R, int G, int B )
{
    if(Surf_Dest == NULL)
    {
        return false;
    }

    SDL_SetColorKey( Surf_Dest, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB( Surf_Dest->format, R, G, B));
    
    return false;
}
