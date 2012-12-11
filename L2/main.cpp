#include "SDL/SDL.h"
#include <string.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define SCREEN_BPP 32

// Defining surfaces
SDL_Surface *message = NULL;
SDL_Surface *background = NULL;
SDL_Surface *screen = NULL;

SDL_Surface *load_image( std:string filename )
{
    // Temp pointer for loaded image
    SDL_Surface *loadedImage = NULL;
     
    // Optimized image pointer
    SDL_Surface *optimizedImage = NULL;

    // Load image
    loadedImage = SDL_LoadBMP( filename.c_str() );

    if( loadedImage )
    {
        // Creating an optimized image
        optimizedImage = SDL_DisplayFormat( loadedImage );

        SDL_FreeSurface( loadedImage );
    }

    return optimizedImage;
}

void apply_surface( int x, int y, SDL_Surface *source, SDL_Surface *destination )
{
    // Temporary rectangle to hold offsets
    SDL_Rect offset;

    offset.x = x;
    offset.y = y;

    // Blit the surface
    SDL_BlitSurface( source, NULL, destination, &offset );
                     
   
