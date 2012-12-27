#include "SDL/SDL.h"
#include <string>
#include "SDL/SDL_image.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 800
#define SCREEN_BPP 32

// Defining Surfaces
SDL_Surface *message = NULL;
SDL_Surface *background = NULL;
SDL_Surface *screen = NULL;

SDL_Surface *load_image( std::string filename )
{
    SDL_Surface *loadedImage = NULL;
    SDL_Surface *optimizedImage = NULL;
    
    loadedImage = IMG_Load( filename.c_str() );

    if(loadedImage != NULL )
    {
        optimizedImage = SDL_DisplayFormat( loadedImage );
        SDL_FreeSurface( loadedImage );
    }

    return optimizedImage;
}
