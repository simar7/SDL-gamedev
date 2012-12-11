#include "SDL/SDL.h"

int main( int argc, char* argv[] )
{
    // The images
    SDL_Surface* hello = NULL;
    SDL_Surface* screen = NULL;

    // Start SDL
    SDL_Init( SDL_INIT_EVERYTHING );

    // Setup Screen
    screen = SDL_SetVideoMode( 640, 480, 32, SDL_SWSURFACE );

    // Load Image
    hello = SDL_LoadBMP( "./hello.bmp" );

    // Apply image to screen
    SDL_BlitSurface( hello, NULL, screen, NULL );

    // Update Screen
    SDL_Flip( screen );

    // Pause
    SDL_Delay( 2000 );

    // Free the loaded image
    SDL_FreeSurface( hello );

    // Quit SDL
    SDL_Quit();

    return 0;
}
