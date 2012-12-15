#include "SDL/SDL.h"
#include <string>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define SCREEN_BPP 32

// Defining surfaces
SDL_Surface *message = NULL;
SDL_Surface *background = NULL;
SDL_Surface *screen = NULL;

SDL_Surface *load_image( std::string filename )
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
                     
}

int main( int argc, char *argv[] )
{
    // Initialize
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return 1;
    }

    // Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );
 
    if( !screen )
    {
        return 1;
    }

    // Window captioning
    SDL_WM_SetCaption( "Hello World - Gangnam Style!", NULL );

    // Load Images
    message = load_image( "gangnam-style-orig.bmp" );
    background = load_image( "background.bmp" );

    // Apply the background to the screen
    apply_surface( 0, 0, background, screen );

    // blitting it three more times to cover the entire screen..
    apply_surface( 320, 0, background, screen );
    apply_surface( 0, 240, background, screen );
    apply_surface( 320, 240, background, screen );
   
    // apply message to the screen
    apply_surface( 180, 140, message, screen );

    if( SDL_Flip( screen ) == -1 )
    {
        return -1;
    }

    SDL_Delay( 10000 );
    
    // Housekeeping...
    SDL_FreeSurface( message );
    SDL_FreeSurface( background );

    SDL_Quit();

    return 0;
} 
